#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main()
{
    std::srand((unsigned int)time(0));

    //1. soru : 1 ile 100 arasında rastgele tam sayılardan oluşan 5x8 matris tanımlayınız. 
    std::cout << "SORU 1  " << std::endl;
    MatrixXd m1 = MatrixXd(5, 8);
    m1.setRandom();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            m1(i, j) = static_cast<int>(100 * abs(m1(i, j)) + 1);
        }
    }
    std::cout << "Matrix m: " << std::endl << m1 << std::endl;

    // 2. soru : Rastgele değerlerle bir 5x4x3 dizi oluşturun.   
    std::cout << "SORU 2 " << std::endl;
    Matrix<Vector3i, 5, 4> matris2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 4; k++) {
                matris2(j, k)[i] = rand() % 100 + 1;
                cout << matris2(j, k)[i] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    //3. soru : Rastgele değerlerle 10x10’luk bir dizi oluşturun ve minimum-maksimum değerleri bulun.
    std::cout << "SORU 3 " << std::endl;
    MatrixXd n = MatrixXd(10, 10);
    n.setRandom();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            n(i, j) = static_cast<int>(100 * abs(n(i, j)) + 1);
        }
    }
    std::cout << "Matrix n: " << std::endl << n << std::endl;
    int  maxV = n.maxCoeff();
    int  minV = n.minCoeff();
    std::cout << "Max value: " << std::endl << maxV << std::endl;
    std::cout << "Min value: " << std::endl << minV << std::endl;


    //4.soru : 5x3 matrisi 3x2 matrisle çarpın. Bu matrislerin elemanlarını karşılıklı olarak çarpın.
    std::cout << "SORU 4  " << std::endl;

    MatrixXd a = MatrixXd(5, 3);
    a.setRandom();
    std::cout << "Matrix a: " << std::endl << a << std::endl;
    MatrixXd b = MatrixXd(3, 2);
    b.setRandom();
    std::cout << "Matrix b: " << std::endl << b << std::endl;

    std::cout << "matrix multiplication :\n" << a * b << std::endl;

    //5. soru: 10 boyutunda rastgele vektör oluşturun ve maksimum değeri 0 ile değiştirin
    std::cout << "SORU 5  " << std::endl;

    VectorXd p(10);
    p = p.setRandom().cwiseAbs();
    std::cout << "vector  : \n " << p << std::endl;
    std::cout << "max value : \n" << p.colwise().maxCoeff() << std::endl;
    for (int i = 0; i < 10; i++) {
        if (p(i) == p.maxCoeff())
        {
            p(i) = 0;
        }
    }
    std::cout << "vector  : \n" << p << std::endl;


    //6. soru: 
    /*
    100x150 boyutlu bir matrisinin her bir satırındaki değerleri satır numarası olacak şekilde MM değişkeninde tanımlayınız.
        111111...
        22222...
        33333...
        .....
        100100100....
    */
    std::cout << "SORU 6  " << std::endl;

    int sayac = 1;
    MatrixXd MM = MatrixXd(100, 150);

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 150; j++) {
            MM(i, j) = sayac;
        }
        sayac++;
    }

    std::cout << "Matrix " << std::endl << MM << std::endl;
    // 7. soru:  MM matrisinin dört parçaya bölündüğünü düşünün.Sağ alt köşe(25x25) ile sol üst köşeyi(25x25), sağ üst köşe(25x25) ile sol alt köşedeki(25x25) değerlerin yerini değiştirin.
    std::cout << "SORU 7  " << std::endl;
    MatrixXd temp = MatrixXd(25, 25);

    temp = MM.topLeftCorner(25, 25);
    MM.topLeftCorner(25, 25) = MM.bottomRightCorner(25, 25);
    MM.bottomRightCorner(25, 25) = temp;

    temp = MM.topRightCorner(25, 25);
    MM.topRightCorner(25, 25) = MM.bottomLeftCorner(25, 25);
    MM.bottomLeftCorner(25, 25) = temp;

    cout << "MM: " << endl << MM << endl;

    //8. soru : 10x10 bir matris içinde 1'den 100'e kadar rakamları saklayın. Bu matrisinin transpozunu yine aynı değişken içerisinde saklayın.
    std::cout << "SORU 8  " << std::endl;

    MatrixXd m8 = MatrixXd(10, 10);
    m8.setRandom();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            m8(i, j) = static_cast<int>(100 * abs(m8(i, j)) + 1);
        }
    }
    std::cout << "Matrix n: " << std::endl << m8 << std::endl;

    m8.transposeInPlace();
    std::cout << "Matrix n Transpoze : " << std::endl << n << std::endl;


    // 9. soru: 10x10 rastgele tam sayılardan oluşan bir matrisin çift sayılı satırları ile çift sayılı sütun elemanlarını yer değiştirin.
    std::cout << "SORU 9  " << std::endl;

    std::srand((unsigned int)time(0));
    MatrixXd matris5 = MatrixXd::Random(10, 10);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matris5(i, j) = static_cast<int>(100 * abs(matris5(i, j)) + 1);
        }
    }

    std::cout << "Matrix " << std::endl << matris5 << std::endl;
    for (int i = 0; i < 10; i += 2) {
        for (int j = 0; j < 10; j++) {
            int x = matris5.col(i)[j];
            matris5.col(i)[j] = matris5.row(i)[j];
            matris5.row(i)[j] = x;
        }
    }

    cout << endl << "Degisen Matrix " << endl << matris5 << endl;

    // 10. soru: 100x100 rastgele sayılardan oluşan bir matris içerisinde sıfırdan küçük değerleri pozitif değerleri ile değiştirin.
    std::cout << "SORU 10  " << std::endl;

    MatrixXd m10 = MatrixXd(100, 100);
    m10.setRandom();
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            m10(i, j) = static_cast<int>(100 * (m10(i, j)) + 1);
        }
    }
    std::cout << "Matrix n: " << std::endl << m10 << std::endl;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (m10(i, j) < 0) {
                m10(i, j) *= -1;
            }
        }
    }
    std::cout << "Matrix m10: " << std::endl << m10 << std::endl;

    // 11. soru 10x10 rastgele tam sayılardan oluşan bir matrisin satırlarındaki değerleri sıralayarak aynı matriste saklayınız.
    std::cout << "SORU 11  " << std::endl;

    MatrixXd matris11 = MatrixXd::Random(10, 10) * 100;
    MatrixXi matris11_cast = matris11.cast<int>().array().abs();
    cout << endl << matris11_cast << endl;
    for (int i = 0; i < 10; i++) {
        VectorXi rows = matris11_cast.row(i);
        std::sort(rows.data(), rows.data() + rows.size());
        matris11_cast.row(i) = rows;
    }
    cout << endl << "siralanmis matris" << endl << matris11_cast << endl;
}
