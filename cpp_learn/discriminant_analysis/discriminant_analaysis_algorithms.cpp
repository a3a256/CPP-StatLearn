#include <iostream>
#include <vector>
#include "../../numcpp/np_define.h"

class LinearDiscriminantAnalysis{
    private:
        std::vector<std::vector<std::vector<float>>> cov_matrices;
        std::vector<std::vector<float>> means;
};