#include<stdio.h>
#include"ref/api.h"

int main(void)
{
	unsigned char pk[CRYPTO_PUBLICKEYBYTES] = {0};
	unsigned char sk[CRYPTO_SECRETKEYBYTES] = {0};
	crypto_sign_keypair(pk, sk);

	const unsigned char* message = (const unsigned char*)"message";
	const size_t message_length = 7;
	unsigned char sigma[CRYPTO_BYTES] = {0};
	size_t sigma_length = 0;
	crypto_sign_signature(sigma, &sigma_length, message, message_length, sk);

	if (crypto_sign_verify(sigma, sigma_length, message, message_length, pk) == 0)
		printf("accept\n");
	else
	 	printf("reject\n");

	const unsigned char* message_prime = (const unsigned char*)"message_prime";
	const size_t message_prime_length = 13;
	if (crypto_sign_verify(sigma, sigma_length, message_prime, message_prime_length, pk) == 0)
		printf("accept\n");
	else
	 	printf("reject\n");

	return 0;
}
