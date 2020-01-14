#include "maptest.capn.h"
#include <unistd.h>
#include <fcntl.h>
#include <capnp/message.h>
#include <capnp/serialize.h>
#include <iostream>
int main()
{

  int in=open("maptest.dat",O_RDONLY );

  ::capnp::StreamFdMessageReader event(in);

  auto hits=event.getRoot<Hits>();
  for (auto hit:hits.getByLayer().getEntries())
    {
      std::cout<<"Hit with key:"<< hit.getKey()<<" "<<hit.getValue().getX()<<std::endl;
    }
    

  close(in);

  return 0;
}
