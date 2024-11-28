#include "Commons.h"
#include "WiFi4.h"
#include "WiFi5.h"
#include "WiFi6.h"

int main() {
    try {
        vector<unique_ptr<Communication>> models;
        models.push_back(make_unique<WiFi4>());
        models.push_back(make_unique<WiFi5>());
        models.push_back(make_unique<WiFi6>());

        vector<int> users = {100,10,1};

        for (const auto& model : models) {
            for (int numUsers : users) {
                model->simulate(numUsers, 1);
                cout << endl;
            }
        }
    } catch (const SimulationException& e) {
        cerr << "Simulation Error: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "General Error: " << e.what() << endl;
    }

    return 0;
}
