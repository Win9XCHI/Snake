#include "Random.h"

/* Init generator
 * Input: -
 * Output: -	 */
void Random::initGenerator() {
    std::random_device device;          //Create a pseudo random grain device
    generator.engine.seed(device());    //Get a random grain of sequence
}

/* Generate random number
 * Input: min and max diapason
 * Output: random numbers	 */
unsigned int Random::random(unsigned minValue, unsigned maxValue) {
    std::uniform_int_distribution<unsigned> distribution(minValue, maxValue);   //Create a distribution
    return distribution(generator.engine);                                      //Calculate a pseudo-random number
}

Random::Random() { 
}

Random::~Random() {
}