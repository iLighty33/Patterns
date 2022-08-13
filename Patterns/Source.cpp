#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

enum Choise_ID {
    Tiger = 1,
    AWPDragonLore = 2,
    TrololoFace = 3
};


class myPicture; // 1st definition
typedef map<Choise_ID, myPicture*> Registry; // definition of the type

// Registry of the prototypes
Registry& getRegistry() {
    static Registry _instance;
    return _instance;
}

// Constructor for helping to choose needed constrictor
class Dummy { };

class myPicture {

public:
    virtual myPicture* clone() const = 0;
    virtual void info() = 0;
    virtual string showPictureTiger() const = 0;
    virtual string showPictureAWPDragonLore() const = 0;
    virtual string showPictureTrololoFace() const = 0;

    static myPicture* createMyPicture(Choise_ID id) {
        Registry& r = getRegistry();
        if (r.find(id) != r.end()) {
            return r[id]->clone();
        return 0;
        }
    }

protected:
    // Adding proptotype to a set of prototypes
    static void addPrototype(Choise_ID id, myPicture* prototype) {
        Registry& r = getRegistry();
        r[id] = prototype;
    }

    // Removing prototype from set of prototypes
    static void removePrototype(Choise_ID id) {
        Registry& r = getRegistry();
        r.erase(r.find(id));
    }

};

class showTigerPicture : myPicture {
public:

    showTigerPicture() {};
    myPicture* clone() const override {
        return new showTigerPicture (*this);
    }


    void info() override {
        std::cout << "1. Tiger\n";
    }
    string showPictureTiger() const override {
        ifstream fs;
        fs.open("tiger.txt", ios::in);
        string str;
        if (fs.is_open()) {
            while (getline(fs, str)) {
                cout << str << endl;
            }
        }
        else
            cout << "Error openning file";
        fs.close();

        this->myPic == str;
        return myPic;
    }

    string showPictureAWPDragonLore() const override {
        ifstream fs;
        fs.open("AWPDragonLore.txt", ios::in);
        string str;
        if (fs.is_open()) {
            while (getline(fs, str)) {
                cout << str << endl;
            }
        }
        else
            cout << "Error openning file";
        fs.close();

        this->myPic == str;
        return myPic;
    }

    string showPictureTrololoFace() const override {
        ifstream fs;
        fs.open("TrololoFace.txt", ios::in);
        string str;
        if (fs.is_open()) {
            while (getline(fs, str)) {
                cout << str << endl;
            }
        }
        else
            cout << "Error openning file";
        fs.close();
        
        this->myPic == str;
        return myPic;
    }

private:

    string myPic;
    showTigerPicture(Dummy) {
        myPicture::addPrototype(Tiger, this);
    };

    static showTigerPicture prototype;

};

class showAWPPicture : myPicture {
    myPicture* clone() const override {
        return new showAWPPicture(*this);
    }
public:
    showAWPPicture() {};
    void info() override {
        std::cout << "2. AWP Dragon Lore\n";
    }
    string showPictureTiger() const override {
        ifstream fs;
        fs.open("tiger.txt", ios::in);
        string str;
        if (fs.is_open()) {
            while (getline(fs, str)) {
                cout << str << endl;
            }
        }
        else
            cout << "Error openning file";
        fs.close();

        this->myPic == str;
        return myPic;
    }

    string showPictureAWPDragonLore() const override {
        ifstream fs;
        fs.open("AWPDragonLore.txt", ios::in);
        string str;
        if (fs.is_open()) {
            while (getline(fs, str)) {
                cout << str << endl;
            }
        }
        else
            cout << "Error openning file";
        fs.close();

        this->myPic == str;
        return myPic;
    }

    string showPictureTrololoFace() const override {
        ifstream fs;
        fs.open("TrololoFace.txt", ios::in);
        string str;
        if (fs.is_open()) {
            while (getline(fs, str)) {
                cout << str << endl;
            }
        }
        else
            cout << "Error openning file";
        fs.close();

        this->myPic == str;
        return myPic;
    }

private:
    string myPic;
    showAWPPicture(Dummy) {
        myPicture::addPrototype(AWPDragonLore, this);
    };

    static showAWPPicture prototype;

};

class showTrololoPicture : myPicture {
    myPicture* clone() const override {
        return new showTrololoPicture(*this);
    }
public:
    showTrololoPicture() {};
    void info() override {
        std::cout << "3. Trololo Face\n";
    }
    string showPictureTiger() const override {
        ifstream fs;
        fs.open("tiger.txt", ios::in);
        string str;
        if (fs.is_open()) {
            while (getline(fs, str)) {
                cout << str << endl;
            }
        }
        else
            cout << "Error openning file";
        fs.close();

        this->myPic == str;
        return myPic;
    }

    string showPictureAWPDragonLore() const override {
        ifstream fs;
        fs.open("AWPDragonLore.txt", ios::in);
        string str;
        if (fs.is_open()) {
            while (getline(fs, str)) {
                cout << str << endl;
            }
        }
        else
            cout << "Error openning file";
        fs.close();

        this->myPic == str;
        return myPic;
    }

    string showPictureTrololoFace() const override {
        ifstream fs;
        fs.open("TrololoFace.txt", ios::in);
        string str;
        if (fs.is_open()) {
            while (getline(fs, str)) {
                cout << str << endl;
            }
        }
        else
            cout << "Error openning file";
        fs.close();

        this->myPic == str;
        return myPic;
    }

private:
    string myPic;
    showTrololoPicture(Dummy) {
        myPicture::addPrototype(TrololoFace, this);
    };

    static showTrololoPicture prototype;

};

showTigerPicture showTigerPicture::prototype = showTigerPicture(Dummy());
showAWPPicture showAWPPicture::prototype = showAWPPicture(Dummy());
showTrololoPicture showTrololoPicture::prototype = showTrololoPicture(Dummy());


int main()
{
    cout << "Prototype" << endl;

    int result;
    vector <myPicture*> myPic;
    std::cout << "Please, enter number:\n";
    std::cout << "1. Tiger\n";
    std::cout << "2. AWP | Dragon Lore\n";
    std::cout << "3. TrololoFace\n";
    std::cin >> result;

    if (result == 1) {
        myPic.push_back(myPicture::createMyPicture(Choise_ID::Tiger)); 
        showTigerPicture* myPicture = new showTigerPicture(); 
        cout << myPicture->showPictureTiger();
    }
    else
        if (result == 2) {
            myPic.push_back(myPicture::createMyPicture(Choise_ID::AWPDragonLore));
            showAWPPicture* myPicture = new showAWPPicture();
            cout << myPicture->showPictureAWPDragonLore();
        }
        else
            if (result == 3) {
                myPic.push_back(myPicture::createMyPicture(Choise_ID::TrololoFace));
                showTrololoPicture* myPicture = new showTrololoPicture();
                cout << myPicture->showPictureTrololoFace();
            }


	return 0;
}