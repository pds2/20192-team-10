//
// Created by User on 25/11/2019.
//

#ifndef INC_20192_TEAM_10_PREMIUM_H
#define INC_20192_TEAM_10_PREMIUM_H


#include "Usuario.h"

class Premium : public Usuario{
    public:
        Premium ();
        Premium(std::string name, std::string username);
        ~Premium() = default;
        void fazerLogin(std::string username) override;
};


#endif //INC_20192_TEAM_10_PREMIUM_H
