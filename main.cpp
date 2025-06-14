#include "raylib.h"
#include <string>

using namespace std;


bool IsButtonClicked(Rectangle rect) {
    return (CheckCollisionPointRec(GetMousePosition(), rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}


float EvaluateExpression(const string& expression) {
    float num1 = 0, num2 = 0;
    char op = 0;


    size_t opIndex = expression.find_first_of("+-*/");
    if (opIndex != string::npos) {
        num1 = stof(expression.substr(0, opIndex));
        op = expression[opIndex];
        num2 = stof(expression.substr(opIndex + 1));
    }
    switch (op) {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/': return num1 / num2;
    default: return 0;
    }
}

int main() {
    InitWindow(460, 600, "Calculator");
    SetTargetFPS(60);

    string currentInput = "0";
    bool clearOnNextInput = false;

    const int button_width = 100, button_height = 80;
    const int margin = 12;

    Rectangle buttons[16];

    string labels[16] = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "C", "0", "=", "+"
    };

    for (int i = 0; i < 16; i++) {
        int row = i / 4;
        int col = i % 4;
        buttons[i] = { float(margin + col * (button_width + margin)),
                       float(150 + row * (button_height + margin)),
                       float(button_width), float(button_height) };
    }


    while (!WindowShouldClose()) {
        for (int i = 0; i < 16; i++) {
            if (IsButtonClicked(buttons[i])) {
                string label = labels[i];

                if (label == "C") {
                    currentInput = "0";
                }
                else if (label == "=") {
                    currentInput = to_string(EvaluateExpression(currentInput));
                    clearOnNextInput = false;
                }
                else {
                    if (clearOnNextInput) {
                        currentInput = label;
                        clearOnNextInput = false;
                    }
                    else {
                        if (currentInput == "0") currentInput = label;
                        else currentInput += label;
                    }
                }
            }
        }

        // Colouring the layout of the interface
        BeginDrawing();
        ClearBackground(PURPLE);

        //designing the box for the display window
        DrawRectangle(10, 10, 440, 120, BLACK);
        DrawText(currentInput.c_str(), 20, 50, 40, WHITE);

        //Button structure
        for (int i = 0; i < 16; i++) {
            DrawRectangleRec(buttons[i], DARKPURPLE);
            DrawText(labels[i].c_str(),
                buttons[i].x + 30, buttons[i].y + 20, 20, WHITE);
        }
        //setting the color of operators
        for (int i = 3; i < 16; i += 4) {
            DrawRectangleRec(buttons[i], RAYWHITE);
            DrawText(labels[i].c_str(),
                buttons[i].x + 30, buttons[i].y + 20, 30, BLACK);
        }
        // setting the color of the clear button
        DrawRectangleRec(buttons[12], RED);
        DrawText(labels[12].c_str(),
            buttons[12].x + 30, buttons[12].y + 30, 20, WHITE);

        // setting the color of the equal button
        DrawRectangleRec(buttons[14], ORANGE);
        DrawText(labels[14].c_str(),
            buttons[14].x + 30, buttons[14].y + 20, 30, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}