/*
 * Copyright (c) 2020 - 2025 the ThorVG project. All rights reserved.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "Example.h"

/************************************************************************/
/* ThorVG Drawing Contents                                              */
/************************************************************************/

struct UserExample : tvgexam::Example
{
    bool content(tvg::Canvas* canvas, uint32_t w, uint32_t h) override
    {
        // Draw a smiling face
        
        // 1. Face (yellow circle)
        auto face = tvg::Shape::gen();
        face->appendCircle(400, 300, 200, 200);  // Center point (400, 300), radius 200
        face->fill(255, 255, 0);                 // Yellow (r, g, b)
        canvas->push(face);

        // 2. Left eye (black circle)
        auto leftEye = tvg::Shape::gen();
        leftEye->appendCircle(350, 250, 20, 20);  // Center point (350, 250), radius 20
        leftEye->fill(0, 0, 0);                   // Black
        canvas->push(leftEye);

        // 3. Right eye (black circle)
        auto rightEye = tvg::Shape::gen();
        rightEye->appendCircle(450, 250, 20, 20); // Center point (450, 250), radius 20
        rightEye->fill(0, 0, 0);                  // Black
        canvas->push(rightEye);

        // 4. Smiling mouth (arc shape)
        auto smile = tvg::Shape::gen();
        smile->moveTo(300, 350);                  // Start point
        smile->cubicTo(300, 400, 500, 400, 500, 350); // Bezier curve for smiling mouth
        smile->strokeFill(0, 0, 0);               // Black stroke
        smile->strokeWidth(3.0f);                 // Stroke width 3
        canvas->push(smile);

        // 5. Nose (small circle shape)
        auto nose = tvg::Shape::gen();
        nose->appendCircle(400, 300, 8, 8);       // Center point (400, 300), radius 8
        nose->fill(255, 200, 200);                // Light pink
        canvas->push(nose);

        // 6. Cheeks (light pink circles)
        auto leftCheek = tvg::Shape::gen();
        leftCheek->appendCircle(320, 320, 15, 15); // Left cheek
        leftCheek->fill(255, 200, 200);            // Light pink
        canvas->push(leftCheek);

        auto rightCheek = tvg::Shape::gen();
        rightCheek->appendCircle(480, 320, 15, 15); // Right cheek
        rightCheek->fill(255, 200, 200);            // Light pink
        canvas->push(rightCheek);

        return true;
    }
};


/************************************************************************/
/* Entry Point                                                          */
/************************************************************************/

int main(int argc, char **argv)
{
    return tvgexam::main(new UserExample, argc, argv);
} 