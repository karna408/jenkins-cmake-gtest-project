#include "Addition.h"
#include <iostream>

namespace zf {
namespace sample {

Addition::Addition(int id) : id_(id) {
  std::cout << "Addition Constructor " << id << std::endl;
}

Addition::~Addition() {}

int Addition::add(int a, int b) { return a + b; }
int Addition::addID(int val) { return add(val,id_); }
int Addition::addOne(int val) { return add(val,1); }
int Addition::addTwo(int val) { return add(val,2); }

} // namespace sample
} // namespace zf