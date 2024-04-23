#include <iostream>
using namespace std;
struct Vagon
{
    int nomer;
    int mistya;
    int pasazhyri;
};
class Train {
private:
    string model;
    int kykistVagon;
    Vagon* vagoni;

public:
    Train() {
        model = "Unknown Model";
        kykistVagon = 0;
        vagoni = nullptr;
    }

    Train(const string& _model, int _kykistVagon) 
    {
        model = _model;
        kykistVagon = _kykistVagon;
        vagoni = new Vagon[kykistVagon];

        for (int i = 0; i < kykistVagon; i++) 
        {
            vagoni[i].nomer = i + 1;
            vagoni[i].mistya = 50;
            vagoni[i].pasazhyri = 0;
        }
    }

    void Show() 
    {
        cout << "Model: " << model << endl;
        cout << "Number of Wagons: " << kykistVagon << endl;

        for (int i = 0; i < kykistVagon; i++) {
            cout << "Wagon #" << vagoni[i].nomer << ":" << endl;
            cout << "\tSeats: " << vagoni[i].mistya << endl;
            cout << "\tPassengers: " << vagoni[i].pasazhyri << endl;
        }
    }
    void AddVagon(int mistya) 
    {
        Vagon* tempVagoni = new Vagon[kykistVagon + 1];

        for (int i = 0; i < kykistVagon; i++) 
        {
            tempVagoni[i] = vagoni[i];
        }

        tempVagoni[kykistVagon].nomer = kykistVagon + 1;
        tempVagoni[kykistVagon].mistya = mistya;
        tempVagoni[kykistVagon].pasazhyri = 0;

        delete[] vagoni;

        vagoni = tempVagoni;
        kykistVagon++;
    }
    void AddPasazhyr(int nomerVagon) 
    {
        if (nomerVagon > 0 && nomerVagon <= kykistVagon) 
        {
            vagoni[nomerVagon - 1].pasazhyri++;
        }
        else 
        {
            cout << "Invalid wagon number!" << endl;
        }
    }
    Train(const Train& other) 
    {
        model = other.model;
        kykistVagon = other.kykistVagon;
        vagoni = new Vagon[kykistVagon];

        for (int i = 0; i < kykistVagon; i++) 
        {
            vagoni[i] = other.vagoni[i];
        }
    }
    ~Train() {
        delete[] vagoni;
    }
};
int main() 
{
    Train train1("Faster", 3);
    train1.AddVagon(70);
    train1.AddPasazhyr(1);
    train1.AddPasazhyr(2);
    train1.AddPasazhyr(4);
    train1.Show();
}