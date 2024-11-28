#include "Commons.h"
#include "WiFi4.h"
#include "WiFi5.h"
#include "WiFi6.h"

int main() {
    try {
        vector<Communication*> models = {new WiFi4(), new WiFi5(), new WiFi6()};
        vector<int> users = {1, 10, 100};

        for (auto& model : models) {
            for (int usersCount : users) {
                model->simulate(usersCount, 1);  // Assuming 1 AP for each case
                cout << endl;
            }
        }

        // Clean up
        for (auto& model : models) {
            delete model;
        }
    }
    catch (const SimulationException& e) {
        cerr << "Simulation Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "General Error: " << e.what() << endl;
    }

    return 0;
}
