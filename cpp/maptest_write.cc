#include "maptest.capn.h"
#include <unistd.h>
#include <fcntl.h>
#include <capnp/message.h>
#include <capnp/serialize.h>

int main()
{

  int out=open("maptest.dat",O_WRONLY |  O_CREAT |O_TRUNC,0666);

  ::capnp::MallocMessageBuilder event;

  auto hits=event.initRoot<Hits>();
  auto byLayer=hits.initByLayer();
  auto entries=byLayer.initEntries(100);
  for (int i=0;i<100;i++)
    {
      entries[i].setKey(i*100);
      auto hit=entries[i].initValue();
    
      hit.setX(i);
      hit.setY(i*10);
      hit.setZ(i*100);
    }

  writeMessageToFd(out,event);

  close(out);

  return 0;
}
