//
// Created by User on 25/11/2019.
//

#ifndef INC_20192_TEAM_10_FREE_H
#define INC_20192_TEAM_10_FREE_H


#include "Usuario.h"

class Free : public Usuario {
    public:
        Free ();
        Free(std::string name, std::string username);
        ~Free()= default;
        void fazerLogin(std::string username) override;
};


#endif //INC_20192_TEAM_10_FREE_H
