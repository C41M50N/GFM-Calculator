#include <iostream>
#include <map>

const std::map<std::string, float> GFMs = {
    {"H",     1.00797f},
    {"He",     4.0026f},
    {"Li",      6.941f},
    {"Be",    9.01218f},
    {"B",       10.81f},
    {"C",      12.011f},
    {"N",     14.0067f},
    {"O",     15.9994f},
    {"F",   18.998403f},
    {"Ne",     20.179f},
    {"Na",   22.98977f},
    {"Mg",     24.305f},
    {"Al",   26.98154f},
    {"Si",    28.0855f},
    {"P",    30.97376f},
    {"S",       32.06f},
    {"Cl",     35.453f},
    {"K",     39.0983f},
    {"Ar",     39.948f},
    {"Ca",      40.08f},
    {"Sc",    44.9559f},
    {"Ti",       47.9f},
    {"V",     50.9415f},
    {"Cr",     51.996f},
    {"Mn",     54.938f},
    {"Fe",     55.847f},
    {"Ni",       58.7f},
    {"Co",    58.9332f},
    {"Cu",     63.546f},
    {"Zn",      65.38f},
    {"Ga",      69.72f},
    {"Ge",      72.59f},
    {"As",    74.9216f},
    {"Se",      78.96f},
    {"Br",     79.904f},
    {"Kr",       83.8f},
    {"Rb",    85.4678f},
    {"Sr",      87.62f},
    {"Y",     88.9059f},
    {"Zr",      91.22f},
    {"Nb",    92.9064f},
    {"Mo",      95.94f},
    {"Tc",       98.0f},
    {"Ru",     101.07f},
    {"Rh",   102.9055f},
    {"Pd",      106.4f},
    {"Ag",    107.868f},
    {"Cd",     112.41f},
    {"In",     114.82f},
    {"Sn",     118.69f},
    {"Sb",     121.75f},
    {"I",    126.9045f},
    {"Te",      127.6f},
    {"Xe",      131.3f},
    {"Cs",   132.9054f},
    {"Ba",     137.33f},
    {"La",   138.9055f},
    {"Ce",     140.12f},
    {"Pr",   140.9077f},
    {"Nd",     144.24f},
    {"Pm",      145.0f},
    {"Sm",      150.4f},
    {"Eu",     151.96f},
    {"Gd",     157.25f},
    {"Tb",   158.9254f},
    {"Dy",      162.5f},
    {"Ho",   164.9304f},
    {"Er",     167.26f},
    {"Tm",   168.9342f},
    {"Yb",     173.04f},
    {"Lu",    174.967f},
    {"Hf",     178.49f},
    {"Ta",   180.9479f},
    {"W",      183.85f},
    {"Re",    186.207f},
    {"Os",      190.2f},
    {"Ir",     192.22f},
    {"Pt",     195.09f},
    {"Au",   196.9665f},
    {"Hg",     200.59f},
    {"Tl",     204.37f},
    {"Pb",      207.2f},
    {"Bi",   208.9804f},
    {"Po",      209.0f},
    {"At",      210.0f},
    {"Rn",      222.0f},
    {"Fr",      223.0f},
    {"Ra",   226.0254f},
    {"Ac",   227.0278f},
    {"Pa",   231.0359f},
    {"Th",   232.0381f},
    {"Np",   237.0482f},
    {"U",     238.029f},
    {"Pu",      242.0f},
    {"Am",      243.0f},
    {"Bk",      247.0f},
    {"Cm",      247.0f},
    {"No",      250.0f},
    {"Cf",      251.0f},
    {"Es",      252.0f},
    {"Hs",      255.0f},
    {"Mt",      256.0f},
    {"Fm",      257.0f},
    {"Md",      258.0f},
    {"Lr",      260.0f},
    {"Rf",      261.0f},
    {"Bh",      262.0f},
    {"Db",      262.0f},
    {"Sg",      263.0f},
    {"Uun",     269.0f},
    {"Uuu",     272.0f},
    {"Uub",     277.0f}
};

std::string getInput(std::string prompt) {
    std::cout << prompt;

    std::string response;
    std::getline(std::cin, response);
    return response;
}

int main(int, char**) {
    std::cout << "### Welcome to the Gram Formula Mass Calculator ###\n";
    std::cout << "* Insert a molecular compound using the following format: 2*H + O\t or press q to exit\n";

    while (true) {
        std::string input = getInput("> ");
        if (input == "q") break;

        float sum = 0.0f;

        // string registers
        std::string s1 = "";
        std::string s2 = "";

        for (char c : input) {
            if (c == ' ') continue;

            else if (c == '*') {
                s2 += c;
            }

            else if (c == '+') {
                // add existing sum
                if (s2.empty()) {
                    float amount = GFMs.at(s1);
                    sum += amount;
                } else {
                    float amount = GFMs.at(s2.substr(1));
                    sum += std::stoi(s1) * amount;
                }

                // reset registers
                s1 = "";
                s2 = "";
            }

            else {
                if (s2.empty()) {
                    s1 += c;
                } else {
                    s2 += c;
                }
            }
            
        }

        // add existing sum
        if (s2.empty()) {
            float amount = GFMs.at(s1);
            sum += amount;
        } else {
            float amount = GFMs.at(s2.substr(1));
            sum += std::stoi(s1) * amount;
        }
        
        std::cout << "GFM: " << sum << std::endl;
    }
}

// TODO: Add Error Handling
