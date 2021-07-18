#include "Random.h"

void Random::initGenerator()
{
    // ������ ������-���������� ��� ��������� ���������� �����.
    std::random_device device;
    // �������� ��������� ����� ������������������
    generator.engine.seed(device());
}

// ���������� ����� ����� � ��������� [minValue, maxValue)
unsigned int Random::random(unsigned minValue, unsigned maxValue) {

    // ������ �������������
    std::uniform_int_distribution<unsigned> distribution(minValue, maxValue);

    // ��������� ��������������� �����: ������� ������������� ��� �������,
    //  ������� ��������� ������������ ����� ����� ��� ��������.
    return distribution(generator.engine);
}

Random::Random() { 
}

Random::~Random() {
}