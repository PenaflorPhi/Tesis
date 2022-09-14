#include <math.h>
#include <stdio.h>

int main() {
  double slope = 0;
  double y_0 = 0;
  int step = 3;
  float step_size = 3.14159265 / step;
  double x_0 = -3.14159265 - step_size;

  for (int i = -1 ; i <= 2 * step + 1; i++) {
    slope = cos(x_0);
    y_0 = sin(x_0);
    printf("\\addplot[domain=-5:5,color=red,thin]");
    if (x_0 <= 0) {
      double x_1 = -x_0;
      printf("{%lf * (x + %f) + %lf};\n", slope, x_1, y_0);
    } else {
      double y_1 = -y_0;
      printf("{%lf * (x - %f) - %lf};\n", slope, x_0, y_1);
    }

		printf("\\addplot+[mark=*, mark options={black},mark size=1pt] coordinates {( %f , %f )};\n", x_0, y_0);
    x_0 += step_size;
  }

  return 0;
}
