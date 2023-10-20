#include "inc/ACN.Config.h"

using namespace ACN::Conf;

int main() {
  new ACN::Conf::Get();
  new ACN::Conf::Put();
  return 0;
}
