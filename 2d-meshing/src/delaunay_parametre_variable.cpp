#include "courbes.h"
#include "scene.h"

const float pas_angle=0.5;

int main(int argv, char **args)
{
    Scene S=Scene();
    S.load("../data/holes.edg");

    int nb_sommets=0;
    for(float angle_min=1;angle_min<=20;angle_min+=pas_angle)
    {
        S.refine_angle_min(angle_min);
        nb_sommets=S.get_number_of_vertices();
        std::cout<<nb_sommets<<std::endl;
    }
    return 0;
}
