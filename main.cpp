#include <iostream>
#include <string>

enum flagNote { DO, RE, MI, FA, SOL, LA, SI };

int main() {
    const int n = 12;
    char note[n];

    // data input
    std::cout << "Enter " << n << " combinations of notes.\n";
    for(int i=0; i<n; i++)
    {
        std::string in;
        bool flagErr;
        char comb;

        // input
        do {
            std::cout << "Enter the " << i << "st combination of notes:";
            std::cin >> in;

            // error checking
            flagErr = false;
            for(int j=0; (j<in.length()) && !flagErr; j++)
                if( (in[j]<'1') || (in[j]>'7') )
                {
                    flagErr = true;
                    std::cout << "Error input. Try again.\n";
                }
        }while( flagErr );

        // data staffing
        comb = 0;
        for(int j=0; j<in.length(); j++)
            comb |= 1<<(int)(in[j]-'1');
        note[i] = comb;
    }

    // data output
    std::cout << "\nResult:\n";
    for(int i=0; i<n; i++)
    {
        std::string out = "";
        char comb = note[i];

        if( comb & (1<<DO)  ) out += "do ";
        if( comb & (1<<RE)  ) out += "re ";
        if( comb & (1<<MI)  ) out += "mi ";
        if( comb & (1<<FA)  ) out += "fa ";
        if( comb & (1<<SOL) ) out += "sol ";
        if( comb & (1<<LA)  ) out += "la ";
        if( comb & (1<<SI)  ) out += "si ";

        std::cout << (i+1) << ": " << out << std::endl;
    }

    return 0;
}
