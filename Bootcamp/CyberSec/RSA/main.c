/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:36:18 by ingonzal          #+#    #+#             */
/*   Updated: 2022/07/15 16:43:19 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "corsair.h"
#include "openssl/bio.h"
#include "openssl/pem.h"
int main()
{
    unsigned int primes = 2;
    unsigned int bits = 1024;
    OSSL_PARAM  params[3];
    EVP_PKEY    *pkey;
    EVP_PKEY_CTX *pctx;
    /* BIO *bio_out = BIO_new(BIO_s_mem()); */
    BIO *bio_out = BIO_new_fp(stdout, BIO_NOCLOSE);
    pkey = NULL;
    pctx = EVP_PKEY_CTX_new_from_name(NULL, "RSA", NULL);
    
    EVP_PKEY_keygen_init(pctx);
    params[0] = OSSL_PARAM_construct_uint("bits", &bits);
    params[1] = OSSL_PARAM_construct_uint("primes", &primes);
    params[2] = OSSL_PARAM_construct_end();
    EVP_PKEY_CTX_set_params(pctx, params);
    EVP_PKEY_generate(pctx, &pkey);
    EVP_PKEY_print_private(bio_out, pkey, 0, NULL);
    EVP_PKEY_CTX_free(pctx);
    BIO_free(bio_out);
    /* printf("Hello ARRRRR mate!\n"); */
    return (0);
}

