#include <iostream>

enum PlayerStatus
{
    PS_Running,
    PS_Walking,
    PS_Crouching
};

float RunSpeed{600.0};
float WalkSpeed{300.0};
float CrouchSpeed{150.0};

void UpdateMovementSpeed(PlayerStatus P_Status, float& speed);
void SwitchOnInt(int i);

int main()
{
    float MovementSpeed;

    PlayerStatus status = PlayerStatus::PS_Running;

    UpdateMovementSpeed(status, MovementSpeed);

    std::cout << "Movement Speed: " << MovementSpeed;

    return 0;
}

void UpdateMovementSpeed(PlayerStatus P_Status, float& speed)
{
    switch (P_Status)
    {
    case PS_Running:
        speed = RunSpeed;
        break;
    case PS_Walking:
        speed = WalkSpeed;
        break;
    case PS_Crouching:
        speed = CrouchSpeed;
        break;
    }
}