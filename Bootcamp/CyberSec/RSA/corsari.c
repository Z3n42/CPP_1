​
#include <stdio.h>
#include "openssl/bio.h"
#include "openssl/pem.h"
#include "openssl/param_build.h"
​
void	generate_rsa_keys_with_primes(unsigned int primes, \
									BIGNUM *p, BIGNUM *q)
{
	(void)primes;
	EVP_PKEY	*pkey;
	EVP_PKEY_CTX *pctx;
	BIO *bio_out = BIO_new_fp(stdout, BIO_NOCLOSE);
	int	status;
	BIGNUM	*n = BN_new();
	BIGNUM	*e = BN_new();
	BN_CTX *ctx_temp;
	ctx_temp = BN_CTX_new();
	if (!ctx_temp)
		printf("Error ctx\n");
	pkey = NULL;
	BN_mul(n, p, q, ctx_temp);
	BN_dec2bn(&e, "65537");
	pctx = EVP_PKEY_CTX_new_from_name(NULL, "RSA", NULL);
	OSSL_PARAM_BLD *params_build = OSSL_PARAM_BLD_new();
    if ( params_build == NULL ) {
		printf("Error\n");
    }
	if ( !OSSL_PARAM_BLD_push_BN(params_build, "n", n) ) {
        printf("Error: failed to push p into param build.\n");
    }
	if ( !OSSL_PARAM_BLD_push_BN(params_build, "e", e) ) {
        printf("Error: failed to push exponent into param build.\n");
    }
	if ( !OSSL_PARAM_BLD_push_BN(params_build, "d", NULL) ) {
        printf("Error: failed to push q into param build.\n");
    }
    OSSL_PARAM *params = OSSL_PARAM_BLD_to_param(params_build);
    if ( params == NULL ) {
        printf("Error: failed to construct params from build.\n");
    }
	status = EVP_PKEY_fromdata_init(pctx);
    if ( status <= 0 ) {
        printf("Error: failed to initialize key creation.\n");
    }
    status = EVP_PKEY_fromdata(pctx, &pkey, EVP_PKEY_KEYPAIR, params);
    if ( status <= 0 || pkey == NULL ) {
        printf("Error: failed to create key.\n");
    }
	EVP_PKEY_print_public(bio_out, pkey, 0, NULL);
	EVP_PKEY_CTX_free(pctx);
	BN_CTX_free(ctx_temp);
	BIO_free(bio_out);
}
