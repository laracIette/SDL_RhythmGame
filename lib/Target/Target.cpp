#include "Target.h"

void Target::Move()
{
    SetX( X() - velocity*deltaTime );
}