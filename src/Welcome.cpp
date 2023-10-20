#include "../inc/Welcome.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/terminal.hpp>

#ifndef ACN_WELCOME_H
#define ACN_WELCOME_H

namespace ACNCLI {
Welcome::Welcome() {
  // Globals
  Element title = text(this->title);

  // Configuration
  Element Conf_main = text("MAIN");
  Element Conf_category = text("CATEGORY");
  Element Conf_key = text("KEY");
  Element Conf_value = text("VALUE");

  // Structure
  Element main_container = gridbox({{Conf_category}, {Conf_key}, {Conf_value}});
  Element inner_window = window(Conf_main, main_container);
  Element main_window = window(title, inner_window) | bgcolor(Color::DarkRed) |
                        color(Color::DarkKhaki);

  // Create screen
  auto screen =
      Screen::Create(Dimension::Fit(main_window), Dimension::Fit(main_window));

  // Render and print
  Render(screen, main_window);
  screen.Print();
}

Welcome::~Welcome() {}
};     // namespace ACNCLI
#endif // !define ACN_WELCOME_H
