//
// Created by Isaac on 2018/2/1.
//

#include "fmtseq.h"
#include "algos_sig.h"
#include "str_match.h"
#include "iohelpers.h"
#include "generator.h"

static algorithm* find_algos(algorithm_suite &AS, std::string &algspec) {
    algorithm* alg = NULL;
    std::string algname;
    for (algorithm_suite::iterator i = AS.begin(), e = AS.end();
         i != e; ++i) {
        if (algorithm_name_matches (algspec, i->first)) {
            if (!alg) {
                algname = i->first;
                alg = i->second;
            } else {
                err ("error: algorithm name "
                             "matches multiple algorithms");
                return NULL;
            }
        }
    }
    return alg;
}

static void fmtseq_test(algorithm_suite &AS) {
    std::string name = "FMTSEQ256H20C-CUBE512-CUBE256";
    algorithm *alg = find_algos(AS, name);

    sencode *pub, *priv;
    ccr_rng r;

    err ("Gathering random seed bits from kernel...");
    err ("If nothing happens, move mouse, type random stuff on keyboard,");
    err ("or just wait longer.");

    if (!r.seed (512, false)) err("seed failed");

    err ("Seeding done, generating the key...");

    if (alg->create_keypair (&pub, &priv, r)) {
        err ("error: key generator failed");
    }

    err("done");
}

int main() {
    algorithm_suite AS;
    //register all available algorithms
    fill_algorithm_suite (AS);

    fmtseq_test(AS);

    return 0;
}
