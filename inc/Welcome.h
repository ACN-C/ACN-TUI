#ifndef ACN_WELCOME
#define ACN_WELCOME

// ftxui
#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/node.hpp"
#include "ftxui/screen/color.hpp"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
using namespace ftxui;

// Basic includes
#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace ACNCLI {
class Welcome {
public:
  Welcome();
  ~Welcome();

private:
  std::string title = "ACNCLI";
};
} // namespace ACNCLI
#endif // !ACN_WELCOME
