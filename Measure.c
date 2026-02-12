#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define PI 3.1415926535
#define HALF 0.5
#define ZERO 0
#define PENTAGON_DEGREE 36
#define STRAIGHT 180
int main(void)
{
    string shape_type = get_string("What's the shape type? 2D or 3D?\n");
    if (strcmp(shape_type, "2D") == ZERO || strcmp(shape_type, "2d") == ZERO)
    {
        string shape = get_string("What's the shape?\n Circle\n Rectangle\n Square\n Triangle\n Pentagon (Regular only)\n");
        if (strcmp(shape, "Circle") == ZERO || strcmp(shape, "circle") == ZERO)
        {
            float Diameter = get_float("What's the Diameter?\n");
            if (Diameter <= ZERO)
            {
                printf("THE DIAMETER CAN'T BE 0 OR LESS! TRY AGAIN.\n");
                return 1;
            }
            string Choose = get_string("Do you want Area or Perimeter?\n");
            string Unit = get_string("What's your unit?\n");
            if (strcmp(Choose, "Area") == ZERO || strcmp(Choose, "area") == ZERO)
            {
                float Area_calc_1 = Diameter * HALF;
                float Area_calc_2 = Area_calc_1 * Area_calc_1;
                float Area = Area_calc_2 * PI;
                printf("The Area ≈ %f %s².\n", Area, Unit);
            }
            else if (strcmp(Choose, "Perimeter") == ZERO || strcmp(Choose, "perimeter") == ZERO)
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
        else if (strcmp(shape, "Rectangle") == ZERO || strcmp(shape, "rectangle") == ZERO)
        {
            float Length = get_float("What's the Length?\n");
            float Width = get_float("What's the Width?\n");
            if (Length <= ZERO || Width <= ZERO)
            {
                printf("THE LENGTH OR WIDTH CAN'T BE 0 OR LESS! TRY AGAIN.\n");
                return 1;
            }
            string Rectangle_Unit = get_string("What's your unit?\n");
            string Rectangle_Choose = get_string("Do you want Area or Perimeter?\n");
            if (strcmp(Rectangle_Choose, "Area") == ZERO || strcmp(Rectangle_Choose, "area") == ZERO)
            {
                float Rectangle_Area = Length * Width;
                printf("The Area = %2.f %s².\n", Rectangle_Area, Rectangle_Unit);
            }
            else if (strcmp(shape, "Perimeter") == ZERO || strcmp(shape, "perimeter") == ZERO)
            {
                float Rectangle_Perimeter = (Length * 2) + (Width * 2);
                printf("The Perimeter = %2.f %s.\n", Rectangle_Perimeter, Rectangle_Unit);
            }
            else
            {
                printf("SYNTAX ERROR! TRY AGAIN BY: ./Measure.\n");
            }
        }
        else if (strcmp(shape, "Square") == ZERO || strcmp(shape, "square") == ZERO)
        {
            float Side = get_float("What's the Side?\n");
            if (Side <= ZERO)
            {
                printf("THE SIDE CAN'T BE 0 OR LESS! TRY AGAIN.\n");
                return 1;
            }
            string Square_Unit = get_string("What's the Unit?\n");
            string Square_Choose = get_string("Do you want Area or Perimeter?\n");
            if (strcmp(Square_Choose, "Area") == ZERO || strcmp(Square_Choose, "area") == ZERO)
            {
                float Square_Area = Side * Side;
                printf("The Area = %2.f %s².\n", Square_Area, Square_Unit);
            }
            else if (strcmp(Square_Choose, "Perimeter") == ZERO || strcmp(Square_Choose, "perimeter") == ZERO)
            {
                float Square_Perimeter = Side * 4;
                printf("The Perimeter = %2.f %s.\n", Square_Perimeter, Square_Unit);
            }
            else
            {
                printf("SYNTAX ERROR! TRY AGAIN BY: ./Measure.\n");
            }
        }
        else if (strcmp(shape, "Triangle") == ZERO || strcmp(shape, "triangle") == ZERO)
        {
            float Height = get_float("What's the Height?\n");
            float Base = get_float("What's the Length of the Base?\n");
            if (Height || Base <= ZERO)
            {
                printf("THE HEIGHT OR BASE CAN'T BE 0 OR LESS! TRY AGAIN.\n");
                return 1;
            }
            string Triangle_Unit = get_string("What's the Unit?\n");
            string Triangle_Type = get_string("Do you want it Equilateral Triangle or Non-Equilateral Triangle?\n");
            if (strcmp(Triangle_Type, "Equilateral") == ZERO || strcmp(Triangle_Type, "equilateral") == ZERO)
            {
                string Triangle_Choose = get_string("Do you want Area or Perimeter?\n");
                if (strcmp(Triangle_Choose, "Area") == ZERO || strcmp(Triangle_Choose, "area") == ZERO)
                {
                    float Triangle_Area = (Base * HALF) * Height;
                    printf("The Area = %2.f %s².\n", Triangle_Area, Triangle_Unit);
                }
                else if (strcmp(Triangle_Choose, "Perimeter") == ZERO || strcmp(Triangle_Choose, "perimeter") == ZERO)
                {
                    float Triangle_Perimeter = Base * 3;
                    printf("The Perimeter = %2.f %s.\n", Triangle_Perimeter, Triangle_Unit);
                }
                else
                {
                    printf("SYNTAX ERROR! TRY AGAIN BY: ./Measure.\n");
                }
            }
            else if (strcmp(Triangle_Type, "Non-Equilateral") == ZERO || strcmp(Triangle_Type, "non-equilateral") == ZERO)
            {
                if (strcmp(Triangle_Type, "Area") == ZERO || strcmp(Triangle_Type, "area") == ZERO)
                {
                    float Triangle_Area = (Base * HALF) * Height;
                    printf("The Area = %2.f %s².\n", Triangle_Area, Triangle_Unit);
                }
                else if (strcmp(Triangle_Type, "Perimeter") == ZERO || strcmp(Triangle_Type, "perimeter") == ZERO)
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
        else if (strcmp(shape, "Pentagon") == ZERO || strcmp(shape, "pentagon") == ZERO)
        {
            string Pentagon_Choose = get_string("Do you want Area or Perimeter?\n");
            string Pentagon_Unit = get_string("What's the Unit?\n");
            if (strcmp(Pentagon_Choose, "Area") == ZERO || strcmp(Pentagon_Choose, "area") == ZERO)
            {
                float Side = get_float("What's the length of the side\n");
                float Radian = PENTAGON_DEGREE * (PI / STRAIGHT);
                float Area = (5 * pow(Side, 2)) / (4 * tan(Radian));
                printf("The Area = %f %s².\n", Area, Pentagon_Unit);
            }
            else if (strcmp(Pentagon_Choose, "Perimeter") == ZERO || strcmp(Pentagon_Choose, "perimeter") == ZERO)
            {
                float Side = get_float("What's the length of the side\n");
                float Perimeter = Side * 5;
                printf("The Perimeter = %2.f %s.\n", Perimeter, Pentagon_Unit);
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
    else if (strcmp(shape_type, "3D") == ZERO || strcmp(shape_type, "3d") == ZERO)
    {
        string shape = get_string("What's the shape?\n Cube\n");
        if (strcmp(shape, "Cube") == ZERO || strcmp(shape, "cube") == ZERO)
        {
            float side_length = get_float("What's the side length?\n");
            string Cube_Choose = get_string("Do you want Volume, Perimeter, or Area?\n");
            string Unit = get_string("What's the Unit?\n");
            if (strcmp(Cube_Choose, "Volume") == ZERO || strcmp(Cube_Choose, "volume") == ZERO)
            {
                float Cube_Volume = side_length * side_length * side_length;
                printf("The Volume = %2.f %s³.\n", Cube_Volume, Unit);
            }
            else if (strcmp(Cube_Choose, "Area") == ZERO || (strcmp(Cube_Choose, "area") == ZERO)
            {
                float Cube_Area = 6 * (side_length * side_length);
                printf("The Area = %2.f %s².\n", Cube_Area, Unit);
            }
            else if (strcmp(Cube_Choose, "Perimeter") == ZERO || (strcmp(Cube_Choose, "perimeter") == ZERO)
            {
                float Cube_Perimeter = 12 * side_length;
                printf("Perimeter = %2.f %s.\n", Cube_Perimeter, Unit);
            }
            else
            {
                printf("SYNTAX ERROR! TRY AGAIN BY: ./Measure.\n");
            }
        }
    }
    else
    {
        printf("SYNTAX ERROR! TRY AGAIN BY: ./Measure.\n");
    }
}
