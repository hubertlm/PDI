#include <opencv2/opencv.hpp>
using namespace cv;

// Função para extrair o n-ésimo bit de cada pixel da imagem, onde o plano varia de 1 a 8
Mat sliced_image(const Mat& input_img, int plano){
    int rows = input_img.rows;
    int cols = input_img.cols;

    uchar mask = 1 << (plano - 1);

    Mat out(rows, cols, CV_8UC1, Scalar(0));
    
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            out.at<uchar>(i, j) = (input_img.at<uchar>(i, j) & mask) ? 
            uchar(255) : uchar(0); 
        }
    }
    return out;
}

int main()
{
    // Leitura da imagem em escala de cinza
    Mat m1 = imread("../Images/Fig0314(a)(100-dollars).tif", IMREAD_GRAYSCALE);
    // Display da imagem original para testes
    imshow("Original", m1);

    // Declaração das variáveis
    int cols, rows, x, y;

    // Extraimos as dimensões da imagem
    cols = m1.cols;
    rows = m1.rows;

    // Print das dimensões da imagem para verificação
    printf("Cols: %d\n", cols);
    printf("Rows: %d\n", rows);

    // Criação das imagens de saída para cada bit
    Mat out1 = sliced_image(m1, 1);
    Mat out2 = sliced_image(m1, 2);
    Mat out3 = sliced_image(m1, 3);
    Mat out4 = sliced_image(m1, 4);
    Mat out5 = sliced_image(m1, 5);
    Mat out6 = sliced_image(m1, 6);
    Mat out7 = sliced_image(m1, 7);
    Mat out8 = sliced_image(m1, 8);

    imshow("Bit 1",out1);
    imwrite("./Figures/out1.tif", out1);
    imshow("Bit 2",out2);
    imwrite("./Figures/out2.tif", out2);
    imshow("Bit 3",out3);
    imwrite("./Figures/out3.tif", out3);
    imshow("Bit 4",out4);
    imwrite("./Figures/out4.tif", out4);
    imshow("Bit 5",out5);
    imwrite("./Figures/out5.tif", out5);
    imshow("Bit 6",out6);
    imwrite("./Figures/out6.tif", out6);
    imshow("Bit 7",out7);
    imwrite("./Figures/out7.tif", out7);
    imshow("Bit 8",out8);
    imwrite("./Figures/out8.tif", out8);

    waitKey(0);

    return 0;
}