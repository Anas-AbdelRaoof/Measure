#include <cs50.h>
#include <stdio.h>
#include <string.h>
#define PI 3.1415926535
#define HALF 0.5
#define ZERO 0
int main(void)
{
    string shape_type = get_string("What's the shape type, 2D or 3D?\n");
    if (strcmp(shape_type, "2D") == ZERO)
    {
        string shape = get_string("What's the shape?\n Circle\n Rectangle\n Square\n Triangle\n");
        if (strcmp(shape, "Circle") == ZERO)
        {
            float Diameter = get_float("What's the Diameter?\n");
            if (Diameter <= ZERO)
            {
                printf("THE DIAMETER CAN'T BE 0 OR LESS! TRY AGAIN.\n");
                return 1;
            }
            string Choose = get_string("Do you want Area or Perimeter?\n");
            string Unit = get_string("What's your unit?\n");
            if (strcmp(Choose, "Area") == ZERO)
            {
                float Area_calc_1 = Diameter * HALF;
                float Area_calc_2 = Area_calc_1 * Area_calc_1;
                float Area = Area_calc_2 * PI;
                printf("The Area ≈ %f %s.\n", Area, Unit);
            }
            else if (strcmp(Choose, "Perimeter") == ZERO)
            {
                float Perimeter_calc = Diameter * HALF;
                float Perimeter = 2 * Perimeter_calc * PI;
                printf("The Perimeter ≈ %f %s.\n", Perimeter, Unit);
            }
            else
            {
                printf("SYNTAX ERROR! TRY AGAIN BY: ./Measure.\n");
            }
        }
        else if (strcmp(shape, "Rectangle") == ZERO)
        {
            float Length = get_float("What's the Length?\n");
            float Width = get_float("What's the Width?\n");
            if (Length || Width <= ZERO)
            {
                printf("THE LENGTH OR WIDTH CAN'T BE 0 OR LESS! TRY AGAIN.\n");
                return 1;
            }
            string Rectangle_Unit = get_string("What's your unit?\n");
            string Rectangle_Choose = get_string("Do you want Area or Perimeter?\n");
            if (strcmp(Rectangle_Choose, "Area") == ZERO)
            {
                float Rectangle_Area = Length * Width;
                printf("The Area = %2.f %s.\n", Rectangle_Area, Rectangle_Unit);
            }
            else if (strcmp(shape, "Perimeter") == ZERO)
            {
                float Rectangle_Perimeter = (Length * 2) + (Width * 2);
                printf("The Perimeter = %2.f %s.\n", Rectangle_Perimeter, Rectangle_Unit);
            }
            else
            {
                printf("SYNTAX ERROR! TRY AGAIN BY: ./Measure.\n");
            }
        }
        else if (strcmp(shape, "Square") == ZERO)
        {
            float Side = get_float("What's the Side?\n");
            if (Side <= ZERO)
            {
                printf("THE SIDE CAN'T BE 0 OR LESS! TRY AGAIN.\n");
                return 1;
            }
            string Square_Unit = get_string("What's the Unit?\n");
            string Square_Choose = get_string("Do you want Area or Perimeter?\n");
            if (strcmp(Square_Choose, "Area") == ZERO)
            {
                float Square_Area = Side * Side;
                printf("The Area = %2.f %s.\n", Square_Area, Square_Unit);
            }
            else if (strcmp(Square_Choose, "Perimeter") == ZERO)
            {
                float Square_Perimeter = Side * 4;
                printf("The Perimeter = %2.f %s.\n", Square_Perimeter, Square_Unit);
            }
            else
            {
                printf("SYNTAX ERROR! TRY AGAIN BY: ./Measure.\n");
            }
        }
        else if (strcmp(shape, "Triangle") == ZERO)
        {
            float Height = get_float("What's the Height?\n");
            float Base = get_float("What's the Length of the Base?\n");
            if (Height || Base <= ZERO)
            {
                printf("THE HEIGHT OR BASE CAN'T BE 0 OR LESS! TRY AGAIN.\n");
                return 1;
            }
            string Triangle_Unit = get_string("What's the Unit?\n");
            string Triangle_Type =
                get_string("Do you want it Equilateral Triangle or Non-Equilateral Triangle?\n");
            if (strcmp(Triangle_Type, "Equilateral") == ZERO)
            {
                string Triangle_Choose = get_string("Do you want Area or Perimeter?\n");
                if (strcmp(Triangle_Choose, "Area") == ZERO)
                {
                    float Triangle_Area = (Base * HALF) * Height;
                    printf("The Area = %2.f %s.\n", Triangle_Area, Triangle_Unit);
                }
                else if (strcmp(Triangle_Choose, "Perimeter") == ZERO)
                {
                    float Triangle_Perimeter = Base * 3;
                    printf("The Perimeter = %2.f %s.\n", Triangle_Perimeter, Triangle_Unit);
                }
                else
                {
                    printf("SYNTAX ERROR! TRY AGAIN BY: ./Measure.\n");
                }
            }
            else if (strcmp(Triangle_Type, "Non-Equilateral") == ZERO)
            {
                if (strcmp(Triangle_Type, "Area") == ZERO)
                {
                    float Triangle_Area = (Base * HALF) * Height;
                    printf("The Area = %2.f %s.\n", Triangle_Area, Triangle_Unit);
                }
                else if (strcmp(Triangle_Type, "Perimeter") == ZERO)
                {
                    float Side_1 = get_float("What's the Length of Side 1?\n");
                    float Side_2 = get_float("What's the Length of Side 2?\n");
                    float Side_3 = get_float("What's the Length of Side 3?\n");
                    float Triangle_Perimeter = Side_1 + Side_2 + Side_3;
                    printf("The Perimeter = %2.f %s.\n", Triangle_Perimeter, Triangle_Unit);
                }
                else
                {
                    printf("SYNTAX ERROR! TRY AGAIN BY: ./Measure.\n");
                }
            }
            else
            {
                printf("SYNTAX ERROR! TRY AGAIN BY: ./Measure.\n");
            }
        }
        else
        {
            printf("SYNTAX ERROR! TRY AGAIN BY: ./Measure.\n");
        }
    }
    else
    {
        printf("SYNTAX ERROR! TRY AGAIN BY: ./Measure.\n");
    }
}
