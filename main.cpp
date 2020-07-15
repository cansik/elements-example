#include <iostream>
#include <elements.hpp>

using namespace cycfi::elements;

auto constexpr bkd_color = rgba(35, 35, 37, 255);
auto background = box(bkd_color);

auto btn_rbox(color c)
{
    return
            layer(
                    margin(
                            { 25, 20, 25, 18 },
                            label("Dogs are my favorite people")
                    ),
                    rbox(c, 10)
            );
}

auto make_button()
{
    return layered_button(
            btn_rbox(colors::medium_blue),            // Normal state
            btn_rbox(colors::medium_blue.level(0.8))  // Pushed state
    );
}

int main(int argc, char *argv[]) {
    std::cout << "Elements Example" << std::endl;

    app _app(argc, argv, "Elements Example", "ch.cansik.example");

    window _win(_app.name());
    _win.on_close = [&_app]() { _app.stop(); };

    view view_(_win);
    view_.content(
            make_button(),
            background
    );

    _app.run();

    return 0;
}
