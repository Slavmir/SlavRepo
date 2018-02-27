#include "pre_proc_definitions.hpp"

int main()
{
    srand(time(NULL));
    int choice;
    do
    {
        std::cout << "1 - generate keys" << std::endl;
        std::cout << "2 - encrypt message" << std::endl;
        std::cout << "0 - exit" << std::endl;
        std::cin >> choice;
        switch(choice)
        {
            case 1:
            rsa_keys();
            break;

            case 2:
            RSAcipher_decipher();
            break;
        }
    }while(choice != 0);

    return (0);
}

void w8(void){
    char c[1];
    std::cin.getline(c, 1);
    std::cin.getline(c, 1);
    for(int i=1; i<500; i++)
        std::cout << std::endl;
}

ULL biggestCommonDivisor(ULL a, ULL b){
    ULL t;
    while(b != 0){
        t = b;
        b = b % a;
        a = t;
    }
    return a;
}

ULL reverseModulus(ULL a, ULL n){
    ULL a0, n0, p0, p1, q, r, t;
    p0 = 0;
    p1 = 1;
    a0 = a;
    n0 = n;
    q = n0 / a0;
    r = n0 % a0;

    while(r > 0){
        t = p0 - q * p1;
        if(t >= 0)
            t = t % n;
        else
            t = n - ((-t) % n);
        p0 = p1;
        p1 = t;
        n0 = a0;
        a0 = r;
        q = n0 / a0;
        r = n0 % a0;
    }
    return p1;
}

void rsa_keys(){
    const unsigned int smallPrimesArray[14] = {3, 5, 7, 11, 13, 17, 19, 21, 23, 29, 31, 39, 41, 51};
    const ULL primes_array[115] =
    {
    121093699, 121093727, 121093747, 121093769, 121093811, 121093813,
    121093823, 121093829, 121093853, 121093867, 121093883, 121093961,
    121093993, 121094003, 121094021, 121094027, 121094041, 121094047,
    121094059, 121094069, 121094093, 121094143, 121094161, 121094177,
    121094189, 121094203, 121094243, 121094269, 121094273, 121094293,
    121094327, 121094329, 121094341, 121094387, 121094399, 121094423,
    121094431, 121094483, 121094503, 121094507, 121094549, 121094591,
    121094647, 121094653, 121094681, 121094683, 121094693, 121094719,
    121094741, 121094761, 121094767, 121094783, 121094797, 121094801,
    121094803, 121094843, 121094863, 121094867, 121094887, 121094891,
    121094899, 121094917, 121094921, 121094933, 121095011, 121095031,
    121095041, 121095047, 121095067, 121095103, 121095119, 121095133,
    121095157, 121095167, 121095173, 121095179, 121095203, 121095209,
    121095239, 121095241, 121095287, 121095307, 121095313, 121095319,
    121095323, 121095361, 121095409, 121095419, 121095421, 121095449,
    121095463, 121095497, 121095523, 121095551, 121095563, 121095571,
    121095581, 121095587, 121095593, 121095613, 121095649, 121095701,
    121095707, 121095739, 121095757, 121095763, 121095769, 121095773,
    121095781, 121095787, 121095847, 121095853, 121095899, 121095929,
    121095973
    };
    ULL key_P, key_Q, phi,n,e,d;
    key_P = primes_array[rand() % 115];
    key_Q = primes_array[rand() % 115];
    phi = (key_P - 1) * (key_Q - 1);
    n = key_P * key_Q;     /// 10848072686786669520
    for(e=primes_array[rand() % 13]; biggestCommonDivisor(e, phi) != 1; e+=2){
        d = reverseModulus(e, phi);
    }
    std::cout << "Write the data that you'll see! For Public keys!" << std::endl;
    std::cout << "Public key!" << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "n: " << n << std::endl;
    std::cout << "Private key!" << std::endl;
    std::cout << "d: " << d << std::endl;
    w8();
}

ULL power_modulo(ULL a, ULL w, ULL n){
        ULL pow, res, q;
        pow = a;
        res = 1;
        for(q=w; q>0; q /=2){
            if(q % 2)
                res = (res * pow) % n;
            pow = (pow * pow) % n;
        }
        return res;
}

void RSAcipher_decipher(){
    ULL e, n ,t;
    std::cout << "RSA cipher" << std::endl;
    std::cout << "Enter e: ";
    std::cin >> e;
    std::cout << "Enter modulus: ";
    std::cin >> n;
    std::cout << "-------------------" << std::endl;
    std::cout << "RSA code (t): " << std::endl;
    std::cin >> t;
    std::cout << power_modulo(t,e,n) << std::endl;
    w8();
}
/**
e: 176796025
n: 14664029540542427
*/
