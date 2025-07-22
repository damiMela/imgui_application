#pragma once

#include <memory> // for std::unique_ptr<T>

/**
    # Example of usage

    @code{.cpp}
    #include <imgui_app/ImGui_Application.hpp>

    #include "imgui.h"

    class MyApp : public ImGui_Application
    {
    protected:

        void drawUi() override
        {
            ImGui::ShowDemoWindow();
        }
    };

    int main()
    {
        MyApp app;
        if(!app.init())
            return 1;

        app.run_main_loop();

        return 0;
    }
    @endcode
*/

class ImGuiApplication
{
    // PIMPL idiom
    class Impl;
    std::unique_ptr<Impl> _impl;

public:

    ImGuiApplication();
    virtual ~ImGuiApplication();

    virtual bool init();
    void runMainLoop();

protected:

    void setClearColor(float r, float g, float b, float a);

    void setWindowTitle(const char* title);
    const char* getWindowTitle() const;

    virtual void drawUi();
    virtual void drawGl();

};
