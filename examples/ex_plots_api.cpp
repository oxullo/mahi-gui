#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

using namespace mahi::gui;
using namespace mahi::util;

class PlotApi : public Application {

    using Application::Application;

    void update() {
        plt1.Flags = ImPlotFlags_Default | ImPlotFlags_Crosshairs;
        ImGui::Begin("Plot 1");
        if (ImGui::BeginPlot("My Plot 1##Derp", &plt1)) {
            ImGui::PlotLine("Data", xs, ys, 4, ImPlotSpec_Cross | ImPlotSpec_Circle, IM_COL_AUTO, {0,0,0,0}, 0, 1, false);
            ImGui::EndPlot();
        }
        ImGui::End();

        ImGui::Begin("Plot 2");
        if (ImGui::BeginPlot("Plot", &plt2, "Time", "Position")) {
            ImGui::PlotLine("Data", xs, ys, 4, ImPlotSpec_Asterisk, IM_COL_AUTO, {0,0,0,0}, 0, 1, false);
            ImGui::EndPlot();
        }
        ImGui::End();
    }

    ImPlot plt1, plt2;
    float xs[4] = {0.1,0.1,0.4,0.9};
    float ys[4] = {0.9,0.2,0.6,0.1};
};

int main(int argc, char const *argv[])
{

    PlotApi api(1000,1000,"Test");
    api.run();
    return 0;
}
