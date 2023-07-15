#include "db_insert.h"
#include "common_records.h"


int db_insert(MYSQL *mysql, __u8 *buff) {
    int rc = 0;
    bool insert_records = false;

    rc = verify_dataset(&buff, insert_records, &mysql);
    if (rc != 0) {
        syslog(LOG_WARNING, "Veryfication of the dataset inside memory buffer FAILED. Dropping data & waiting new interval ds. \n");
        return -1;
    } else {
        insert_records = true;
        rc = verify_dataset(&buff, insert_records);
    }

    return 0;
}

static int verify_dataset( __u8 *buff, bool insert_records, MYSQL *mysql ) {
    //  d1r11 = interval end
    //  d1r13 = end of frame indicator

    int mce_length = 0;
    int rec_length = 0;

    struct mce *ptr_mce;
    ptr_mce = (struct mce *) buff;
    struct header *ptr_hdr;
    ptr_hdr = (struct hdr *) ptr_mce;

    while ( ptr_mce < ACTIVE_BUFFER_END )
        mce_length = ptr_mce->rec_end - ptr_mce->rec_start;
        if ( mce_length == 0 ) {
            break;
        }
        ptr_hdr += sizeof(struct mce);
        rec_length = mce_length;

        while ( rec_length - ptr_hdr->rec_lenght >= 0 ) {
            if ( ( ptr_hdr->domain_id = 1 ) && ( ptr_hdr->rec_id == 11 ) ) {
                return 0;
            } else if ( insert_records ) {
                v53insert(ptr_hdr->domain_id, ptr_hdr->rec_id, , );
                
            }
        ptr_hdr += ptr_hdr->rec_lenght;    
        }
        ptr_mce += mce_length;
    }
    return -2;
}


int v53insert(__u8 d, __u16 r, *mysql, __u8 *b) {
    char qbuf[4096];
    memset(qbuf, 0, 4096);
    bool unkn_flag = false;

    switch (d) {
        case 0:
            switch (r) {
                case 1:
                    struct d0r1 *d0r1p;
                    d0r1p = (struct d0r1 *) b;
                    //  SQL QUERY R-1
                    sprintf(qbuf, "INSERT INTO d0r1 VALUES ('',FROM_UNIXTIME(%u),'%hu','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
                        utc,
                        d0r1p->sytsyp_pfxcpuad,
                        d0r1p->sytsyp_plsabnct,
                        d0r1p->sytsyp_plsdiagt,
                        d0r1p->sytsyp_plsprvis,
                        d0r1p->sytsyp_plsextnx,
                        d0r1p->sytsyp_plsextnc,
                        d0r1p->sytsyp_plsmchct,
                        d0r1p->sytsyp_plsctss,
                        d0r1p->sytsyp_plsctrs,
                        d0r1p->sytsyp_plsctcs,
                        d0r1p->sytsyp_plscths,
                        d0r1p->sytsyp_plsctsi,
                        d0r1p->sytsyp_plsctui,
                        d0r1p->sytsyp_plspiopr,
                        d0r1p->sytsyp_plspiopw,
                        d0r1p->sytsyp_plspiosr,
                        d0r1p->sytsyp_plspiosw,
                        d0r1p->sytsyp_plsdguct,
                        d0r1p->sytsyp_plsxitct,
                        d0r1p->sytsyp_plspagps,
                        d0r1p->sytsyp_plsstkpe,
                        d0r1p->sytsyp_plstmrce,
                        d0r1p->sytsyp_plsprvsc,
                        d0r1p->sytsyp_pfxcputy);
                    break;
                case 2:
                    struct d0r2 *d0r2p;
                    d0r2p = (struct d0r2 *) b;

                    break;
                case 3:
                    struct d0r3 *d0r3p;
                    d0r3p = (struct d0r3 *) b;
                    //  SQL QUERY R-3
                    sprintf(qbuf, "INSERT INTO d0r3 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%s','%u','%s','%u','%u','%u','%u','%u','%u','%u','%u','%u','%s','%u','%u','%u','%s','%u','%s','%s','%s','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
                        utc,
                        d0r3p->sytrsg_sysrsvpg,
                        d0r3p->sytrsg_rsacplok,
                        d0r3p->sytrsg_rsanonpg,
                        d0r3p->sytrsg_rsapgabl,
                        d0r3p->sytrsg_rsaavail,
                        d0r3p->sytrsg_rsafrqwt,
                        d0r3p->sytrsg_rsaxtend,
                        d0r3p->sytrsg_rsasavfr,
                        d0r3p->sytrsg_calflag1,
                        d0r3p->sytrsg_hcpstpmb,
                        d0r3p->sytrsg_sys98xa,
                        d0r3p->sytrsg_tcmmidsz,
                        d0r3p->sytrsg_tcmmain,
                        d0r3p->sytrsg_tcmmnmin,
                        d0r3p->sytrsg_tcmmnmax,
                        d0r3p->sytrsg_tcmmndl,
                        d0r3p->sytrsg_tcmstlmn,
                        d0r3p->sytrsg_sysscmav,
                        d0r3p->sytrsg_tcmmnblw,
                        d0r3p->sytrsg_tcmmnabv,
                        d0r3p->sytrsg_rsa2gdct,
                        d0r3p->sytrsg_sysscgct,
                        d0r3p->sytrsg_rsalgfrm,
                        d0r3p->sytrsg_rsacplkg,
                        d0r3p->sytrsg_rsa2gavl,
                        d0r3p->sytrsg_rsa2gav1,
                        d0r3p->sytrsg_rsa2gav2,
                        d0r3p->sytrsg_rsafsb2g,
                        d0r3p->sytrsg_rsafsa2g,
                        d0r3p->sytrsg_rsafsyub,
                        d0r3p->sytrsg_rsafsyua,
                        d0r3p->sytrsg_rsasxcpl,
                        d0r3p->sytrsg_rsasxcla,
                        d0r3p->sytrsg_rsarfrst,
                        d0r3p->sytrsg_rsarfrsg,
                        d0r3p->sytrsg_rsasxbct,
                        d0r3p->sytrsg_rsasxact,
                        d0r3p->sytrsg_rsaafrdb,
                        d0r3p->sytrsg_rsaafrdw,
                        d0r3p->sytrsg_rsaafrib,
                        d0r3p->sytrsg_rsaafriu,
                        d0r3p->sytrsg_rsacalct,
                        d0r3p->sytrsg_rsasng2g,
                        d0r3p->sytrsg_rsasngav,
                        d0r3p->sytrsg_rsaltdb1,
                        d0r3p->sytrsg_rsaltda1,
                        d0r3p->sytrsg_rsaltdd1,
                        d0r3p->sytrsg_rsaltdc1,
                        d0r3p->sytrsg_rsaltdb2,
                        d0r3p->sytrsg_rsaltda2,
                        d0r3p->sytrsg_rsaltdd2,
                        d0r3p->sytrsg_rsaltdc2,
                        d0r3p->sytrsg_rsaltdbe,
                        d0r3p->sytrsg_rsaltdae,
                        d0r3p->sytrsg_rsaltdde,
                        d0r3p->sytrsg_rsaltdce,
                        d0r3p->sytrsg_rsadrmb1,
                        d0r3p->sytrsg_rsadrma1,
                        d0r3p->sytrsg_rsadrmd1,
                        d0r3p->sytrsg_rsadrmc1,
                        d0r3p->sytrsg_rsadrmb2,
                        d0r3p->sytrsg_rsadrma2,
                        d0r3p->sytrsg_rsadrmd2,
                        d0r3p->sytrsg_rsadrmc2,
                        d0r3p->sytrsg_rsadrmbe,
                        d0r3p->sytrsg_rsadrmae,
                        d0r3p->sytrsg_rsadrmde,
                        d0r3p->sytrsg_rsadrmce,
                        d0r3p->sytrsg_rsaelgb1,
                        d0r3p->sytrsg_rsaelga1,
                        d0r3p->sytrsg_rsaelgd1,
                        d0r3p->sytrsg_rsaelgc1,
                        d0r3p->sytrsg_rsaelgb2,
                        d0r3p->sytrsg_rsaelga2,
                        d0r3p->sytrsg_rsaelgd2,
                        d0r3p->sytrsg_rsaelgc2,
                        d0r3p->sytrsg_rsaelgbe,
                        d0r3p->sytrsg_rsaelgae,
                        d0r3p->sytrsg_rsaelgde,
                        d0r3p->sytrsg_rsaelgce,
                        d0r3p->sytrsg_rsadspb1,
                        d0r3p->sytrsg_rsadspa1,
                        d0r3p->sytrsg_rsadspd1,
                        d0r3p->sytrsg_rsadspc1,
                        d0r3p->sytrsg_rsadspb2,
                        d0r3p->sytrsg_rsadspa2,
                        d0r3p->sytrsg_rsadspd2,
                        d0r3p->sytrsg_rsadspc2,
                        d0r3p->sytrsg_rsadspbe,
                        d0r3p->sytrsg_rsadspae,
                        d0r3p->sytrsg_rsadspde,
                        d0r3p->sytrsg_rsadspce,
                        d0r3p->sytrsg_rsashrb1,
                        d0r3p->sytrsg_rsashra1,
                        d0r3p->sytrsg_rsashrd1,
                        d0r3p->sytrsg_rsashrc1,
                        d0r3p->sytrsg_rsashrb2,
                        d0r3p->sytrsg_rsashra2,
                        d0r3p->sytrsg_rsashrd2,
                        d0r3p->sytrsg_rsashrc2,
                        d0r3p->sytrsg_rsashrbe,
                        d0r3p->sytrsg_rsashrae,
                        d0r3p->sytrsg_rsashrde,
                        d0r3p->sytrsg_rsashrce,
                        d0r3p->sytrsg_rsaresac,
                        d0r3p->sytrsg_rsaresbc);
                    break;
                case 4:
                    struct d0r4 *d0r4p;
                    d0r4p = (struct d0r4 *) b;
                    //  SQL QUERY R-4
                    sprintf(qbuf, "INSERT INTO d0r4 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
                        utc,
                        d0r4p->sytrsp_pfxcpuad,
                        d0r4p->sytrsp_plsstlfr,
                        d0r4p->sytrsp_plsprqdf,
                        d0r4p->sytrsp_plsshrrd,
                        d0r4p->sytrsp_plsalemp,
                        d0r4p->sytrsp_plsnocmp,
                        d0r4p->sytrsp_plsmvb2g,
                        d0r4p->sytrsp_plsalemg,
                        d0r4p->sytrsp_plsgclem,
                        d0r4p->sytrsp_plsmvabv,
                        d0r4p->sytrsp_pfxcputy,
                        d0r4p->sytrsp_plsalecl,
                        d0r4p->sytrsp_plsalecg);
                    break;
                case 5:
                    struct d0r5 *d0r5p;
                    d0r5p = (struct d0r5 *) b;
                    //  SQL QUERY R-5
                    sprintf(qbuf, "INSERT INTO d0r5 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u')",
                        utc,
                        d0r5p->sytxsp_pfxcpuad,
                        d0r5p->sytxsp_pfxpgin,
                        d0r5p->sytxsp_plspgin,
                        d0r5p->sytxsp_plspgout,
                        d0r5p->sytxsp_plspgxrd,
                        d0r5p->sytxsp_plspgxwt,
                        d0r5p->sytxsp_plspgmrx,
                        d0r5p->sytxsp_plspgmrd,
                        d0r5p->sytxsp_pfxcputy);
                    break;
                case 6:
                    struct d0r6 *d0r6p;
                    d0r6p = (struct d0r6 *) b;
                    //  SQL QUERY R-6
                    sprintf(qbuf, "INSERT INTO d0r6 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
                        utc,
                        d0r6p->sytasg_cal90ful,
                        d0r6p->sytasg_cal91ful,
                        d0r6p->sytasg_calslta1,
                        d0r6p->sytasg_calslti1,
                        d0r6p->sytasg_calslta2,
                        d0r6p->sytasg_calslti2,
                        d0r6p->sytasg_syssfcrt,
                        d0r6p->sytasg_syssfpur,
                        d0r6p->sytasg_caltotm1,
                        d0r6p->sytasg_calavgm1,
                        d0r6p->sytasg_caltotm2,
                        d0r6p->sytasg_calavgm2,
                        d0r6p->sytasg_caldmpav,
                        d0r6p->sytasg_caldmpiu);
                    break;
                case 7:
                    struct d0r7 *d0r7p;
                    d0r7p = (struct d0r7 *) b;
                    //  SQL QUERY R-7
                    sprintf(qbuf, "INSERT INTO d0r7 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
                        utc,
                        d0r7p->sytshs_systanss,
                        d0r7p->sytshs_systadcs,
                        d0r7p->sytshs_rsashare,
                        d0r7p->sytshs_calnumsa,
                        d0r7p->sytshs_rsactshr,
                        d0r7p->sytshs_vmdsforo,
                        d0r7p->sytshs_vmdsfore,
                        d0r7p->sytshs_qdgsyslm,
                        d0r7p->sytshs_qdgusrlm,
                        d0r7p->sytshs_qdgsysca,
                        d0r7p->sytshs_qdglkcnt,
                        d0r7p->sytshs_qdgdisks);
                    break;
                case 8:

                    break;
                case 9:

                    break;
                case 10:

                    break;
                case 11:
                    struct d0r11 *d0r11p;
                    d0r11p = (struct d0r11 *) b;
                    //  SQL QUERY R-11
                    sprintf(qbuf, "INSERT INTO d0r11 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d0r11p->sytcom_pfxcpuad,
                        d0r11p->sytcom_plsisevm,
                        d0r11p->sytcom_plsisema,
                        d0r11p->sytcom_plsisem,
                        d0r11p->sytcom_plsisera,
                        d0r11p->sytcom_plsisebl,
                        d0r11p->sytcom_plsisemo,
                        d0r11p->sytcom_plsistma,
                        d0r11p->sytcom_plsistvm,
                        d0r11p->sytcom_plsistm,
                        d0r11p->sytcom_plsistra,
                        d0r11p->sytcom_plsistbl,
                        d0r11p->sytcom_plsistmo,
                        d0r11p->sytcom_plsisuvm,
                        d0r11p->sytcom_plsisuma,
                        d0r11p->sytcom_plsisum,
                        d0r11p->sytcom_plsisura,
                        d0r11p->sytcom_plsisubl,
                        d0r11p->sytcom_plsisumo,
                        d0r11p->sytcom_plsvsevm,
                        d0r11p->sytcom_plsvstvm,
                        d0r11p->sytcom_plsvsuvm,
                        d0r11p->sytcom_plsisecc,
                        d0r11p->sytcom_plsistcc,
                        d0r11p->sytcom_plsisucc,
                        d0r11p->sytcom_plsisesi,
                        d0r11p->sytcom_plsistsi,
                        d0r11p->sytcom_plsisusi,
                        d0r11p->sytcom_plsisesp,
                        d0r11p->sytcom_plsistsp,
                        d0r11p->sytcom_plsisusp,
                        d0r11p->sytcom_plsisesy,
                        d0r11p->sytcom_plsistsy,
                        d0r11p->sytcom_plsisusy,
                        d0r11p->sytcom_plsiseac,
                        d0r11p->sytcom_plsistac,
                        d0r11p->sytcom_plsisuac,
                        d0r11p->sytcom_plsiselo,
                        d0r11p->sytcom_plsistlo,
                        d0r11p->sytcom_plsisulo,
                        d0r11p->sytcom_plsisecr,
                        d0r11p->sytcom_plsistcr,
                        d0r11p->sytcom_plsisucr,
                        d0r11p->sytcom_plsiseid,
                        d0r11p->sytcom_plsistid,
                        d0r11p->sytcom_plsisuid,
                        d0r11p->sytcom_plsisecf,
                        d0r11p->sytcom_plsistcf,
                        d0r11p->sytcom_plsisucf,
                        d0r11p->sytcom_plsiucvt,
                        d0r11p->sytcom_pfxcputy,
                        d0r11p->sytcom_plsisevs,
                        d0r11p->sytcom_plsistvs,
                        d0r11p->sytcom_plsisuvs,
                        d0r11p->sytcom_plsiseas,
                        d0r11p->sytcom_plsistas,
                        d0r11p->sytcom_plsisuas,
                        d0r11p->sytcom_plsisesc,
                        d0r11p->sytcom_plsistsc,
                        d0r11p->sytcom_plsisusc,
                        d0r11p->sytcom_plsiseve,
                        d0r11p->sytcom_plsistve,
                        d0r11p->sytcom_plsisuve);
                    break;
                case 12:
                    struct d0r12 *d0r12p;
                    d0r12p = (struct d0r12 *) b;
                    //  SQL QUERY R-12
                    sprintf(qbuf, "INSERT INTO d0r12 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%i','%i','%i','%i','%i','%i','%i','%i','%i','%u','%i','%u','%u','%u','%u','%u','%u','%i','%i','%i','%i','%i','%i','%i','%i','%i','%i','%i','%i','%i','%i','%i','%i')",
			            utc,
                        d0r12p->sytuwt_caltidl,
                        d0r12p->sytuwt_caltsvm,
                        d0r12p->sytuwt_caliowt,
                        d0r12p->sytuwt_calwtpag,
                        d0r12p->sytuwt_calcfwt,
                        d0r12p->sytuwt_calsimwt,
                        d0r12p->sytuwt_calcpuwt,
                        d0r12p->sytuwt_calcpurn,
                        d0r12p->sytuwt_calothr,
                        d0r12p->sytuwt_calqdisp,
                        d0r12p->sytuwt_calelsvm,
                        d0r12p->sytuwt_srmcelig,
                        d0r12p->sytuwt_srmdsvmw,
                        d0r12p->sytuwt_calioact,
                        d0r12p->sytuwt_calllist,
                        d0r12p->sytuwt_calllcp,
                        d0r12p->sytuwt_calllzap,
                        d0r12p->sytuwt_calllifl,
                        d0r12p->sytuwt_calllzip,
                        d0r12p->sytuwt_calcfcp,
                        d0r12p->sytuwt_calcfzap,
                        d0r12p->sytuwt_calcfifl,
                        d0r12p->sytuwt_calcfzip,
                        d0r12p->sytuwt_calswcp,
                        d0r12p->sytuwt_calswzap,
                        d0r12p->sytuwt_calswifl,
                        d0r12p->sytuwt_calswzip,
                        d0r12p->sytuwt_calcwcp,
                        d0r12p->sytuwt_calcwzap,
                        d0r12p->sytuwt_calcwifl,
                        d0r12p->sytuwt_calcwzip,
                        d0r12p->sytuwt_calcrcp,
                        d0r12p->sytuwt_calcrzap,
                        d0r12p->sytuwt_calcrifl,
                        d0r12p->sytuwt_calcrzip);
                    break;
                case 13:
                    struct d0r13 *d0r13p;
                    d0r13p = (struct d0r13 *) b;
                    //  SQL QUERY R-13
                    sprintf(qbuf, "INSERT INTO d0r13 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d0r13p->sytscp_pfxcpuad,
                        d0r13p->sytscp_plseqkad,
                        d0r13p->sytscp_plsefrc1,
                        d0r13p->sytscp_plsefrc2,
                        d0r13p->sytscp_plsefrc3,
                        d0r13p->sytscp_plsdspcn,
                        d0r13p->sytscp_pfxcputy);
                    break;
                case 14:
                    struct d0r14 *d0r14p;
                    d0r14p = (struct d0r14 *) b;
                    //  SQL QUERY R-14
                    sprintf(qbuf, "INSERT INTO d0r14 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%s','%s','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d0r14p->sytxsg_xstxbget,
                        d0r14p->sytxsg_xstxbrel,
                        d0r14p->sytxsg_xstusrsh,
                        d0r14p->sytxsg_xstctxav,
                        d0r14p->sytxsg_xstcppar,
                        d0r14p->sytxsg_hcpmdcpy,
                        d0r14p->sytxsg_hcpmdcpn,
                        d0r14p->sytxsg_hcpmdcpr,
                        d0r14p->sytxsg_hcpmdcpw,
                        d0r14p->sytxsg_hcpmdcac,
                        d0r14p->sytxsg_hcpmdcne,
                        d0r14p->sytxsg_hcpmdcex,
                        d0r14p->sytxsg_hcpmdcli,
                        d0r14p->sytxsg_calmdcau,
                        d0r14p->sytxsg_hcpmdcis,
                        d0r14p->sytxsg_hcpmdcqc,
                        d0r14p->sytxsg_hcpmdcxg,
                        d0r14p->sytxsg_hcpmdcxr,
                        d0r14p->sytxsg_hcpmdctr,
                        d0r14p->sytxsg_hcpmdcia,
                        d0r14p->sytxsg_hcpmdcib,
                        d0r14p->sytxsg_hcpmdcit,
                        d0r14p->sytxsg_tcmxidsz,
                        d0r14p->sytxsg_tcmxsmin,
                        d0r14p->sytxsg_tcmstlxs,
                        d0r14p->sytxsg_xstavgag,
                        d0r14p->sytxsg_hcpstpxb,
                        d0r14p->sytxsg_tcmfshvm,
                        d0r14p->sytxsg_tcmrdct,
                        d0r14p->sytxsg_tcmpin4k);
                    break;
                case 15:
                    struct d0r15 *d0r15p;
                    d0r15p = (struct d0r15 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d0r15p->sytcug_lparname,8);
                    //  SQL QUERY R-15
                    sprintf(qbuf, "INSERT INTO d0r15 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%s','%u','%u','%u')",
			            utc,
                        d0r15p->sytcug_lcutnpar,
                        d0r15p->sytcug_lcutflag,
                        d0r15p->sytcug_lcutslce,
                        d0r15p->sytcug_lcutpcct,
                        d0r15p->sytcug_lpnumber,
                        d0r15p->sytcug_cpuchar,
                        d0r15p->sytcug_cpucount,
                        d0r15p->sytcug_cpucfgct,
                        d0r15p->sytcug_cpustnby,
                        d0r15p->sytcug_cpuresvd,
                        d0r15p->sytcug_lparname,
                        d0r15p->sytcug_lparcaf,
                        d0r15p->sytcug_cpudedct,
                        d0r15p->sytcug_cpushard);
                    break;
                case 16:

                    break;
                case 17:

                    break;
                case 18:

                    break;
                case 19:
                	//  not tested
                    struct d0r19 *d0r19p;
                    d0r19p = (struct d0r19 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d0r19p->sytsyg_vl3mname,8);
                    e2a(d0r19p->sytsyg_vl3cpnam,16);
                    //  SQL QUERY R-19
                    sprintf(qbuf, "INSERT INTO d0r19 VALUES ('',FROM_UNIXTIME(%u),'%s','%u','%u','%u','%u',%u','%u','%u','%u','%u',%u','%u','%u','%u','%u',%u','%u','%u','%u','%s','%u','%s')",
			            utc,
                        d0r19p->sytsyg_xctmsact,
                        d0r19p->sytsyg_ftrdone,
                        d0r19p->sytsyg_ftrabort,
                        d0r19p->sytsyg_ftrnotel,
                        d0r19p->sytsyg_ftrwrite,
                        d0r19p->sytsyg_ctndone,
                        d0r19p->sytsyg_ctnabort,
                        d0r19p->sytsyg_ctnnotel,
                        d0r19p->sytsyg_scpcapab,
                        d0r19p->sytsyg_cpucapab,
                        d0r19p->sytsyg_cpucount,
                        d0r19p->sytsyg_cpucfgct,
                        d0r19p->sytsyg_cpustnby,
                        d0r19p->sytsyg_cpuresvd,
                        d0r19p->sytsyg_vl3dbct,
                        d0r19p->sytsyg_vl3count,
                        d0r19p->sytsyg_vl3cfgct,
                        d0r19p->sytsyg_vl3stnby,
                        d0r19p->sytsyg_vl3resvd,
                        d0r19p->sytsyg_vl3mname,
                        d0r19p->sytsyg_vl3caf,
                        d0r19p->sytsyg_vl3cpnam);
                    break;
                case 20:
                    
                    break;
                case 21:
                    struct d0r21 *d0r21p;
                    d0r21p = (struct d0r21 *) b;
                    //  SQL QUERY R-21
                    sprintf(qbuf, "INSERT INTO d0r21 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d0r21p->sytsxg_sxssize,
                        d0r21p->sytsxg_rsasxavl,
                        d0r21p->sytsxg_rsasxbka,
                        d0r21p->sytsxg_rsasxbkb,
                        d0r21p->sytsxg_rsasxusd,
                        d0r21p->sytsxg_rsasxucp,
                        d0r21p->sytsxg_rsasxuid,
                        d0r21p->sytsxg_rsasxufs,
                        d0r21p->sytsxg_rsasxufg,
                        d0r21p->sytsxg_rsasxali,
                        d0r21p->sytsxg_rsasxnop,
                        d0r21p->sytsxg_rsasxcla,
                        d0r21p->sytsxg_rsasxqct,
                        d0r21p->sytsxg_rsasxact,
                        d0r21p->sytsxg_rsasxbct,
                        d0r21p->sytsxg_rsarsvsy);
                    break;
                case 22:
                    struct d0r22 *d0r22p;
                    d0r22p = (struct d0r22 *) b;
                    //  SQL QUERY R-22
                    sprintf(qbuf, "INSERT INTO d0r22 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d0r22p->sytsxp_pfxcpuad,
                        d0r22p->sytsxp_plssxrep,
                        d0r22p->sytsxp_plssxacc,
                        d0r22p->sytsxp_plssxarc,
                        d0r22p->sytsxp_plssxaqc,
                        d0r22p->sytsxp_plsspfsc,
                        d0r22p->sytsxp_plsspgpc,
                        d0r22p->sytsxp_plsspgcc,
                        d0r22p->sytsxp_plsspgct,
                        d0r22p->sytsxp_plssprpc,
                        d0r22p->sytsxp_plssprcc,
                        d0r22p->sytsxp_plssprct,
                        d0r22p->sytsxp_plssprqc,
                        d0r22p->sytsxp_plssprqt,
                        d0r22p->sytsxp_plsspgfc,
                        d0r22p->sytsxp_plssprfc,
                        d0r22p->sytsxp_pfxcputy);
                    break;
                case 23:
                    
                    break;
                case 24:
                    
                    break;        
                            
                default:
                    unkn_flag = true;
                    break
                }
            break;
        case 1:
            switch (r) {
                case 1:
                    struct d1r1 *d1r1p;
                    d1r1p = (struct d1r1 *) b;
                    //  SQL QUERY R-1
                    sprintf(qbuf, "INSERT INTO d1r1 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u')",
			        utc,
			        d1r1p->mtrepr_edomains,
			        d1r1p->ibm,
			        d1r1p->mtrepr_config);
                    break;
                case 2:

                    break;
                case 3:
                    struct d1r3 *d1r3p;
                    d1r3p = (struct d1r3 *) b;
                    //  SQL QUERY R-3
                    sprintf(qbuf, "INSERT INTO d1r3 VALUES ('',FROM_UNIXTIME(%u),'%u')",
			            utc,
			            d1r3p->mtrsus_lostrcct);
                    break;
                case 4:
                    struct d1r4 *d1r4p;
                    d1r4p = (struct d1r4 *) b;
                    break;
                case 5:
                    struct d1r5 *d1r5p;
                    d1r5p = (struct d1r5 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d1r5p->mtrprp_pfxidmdl,2);
                    e2a(d1r5p->mtrprp_pfxidser,3);
                    e2a(d1r5p->mtrprp_caluded,8);
                    //  SQL QUERY R-5
                    sprintf(qbuf, "INSERT INTO d1r5 VALUES ('',FROM_UNIXTIME(%u),'%u','%s','%s','%u','%u','%u','%u','%s','%u')",
			            utc,
                        d1r5p->mtrprp_pfxcpuad,
                        d1r5p->mtrprp_pfxidmdl,
                        d1r5p->mtrprp_pfxidser,
                        d1r5p->mtrprp_calflags,
                        d1r5p->mtrprp_pcccsu,
                        d1r5p->mtrprp_pfxidver,
                        d1r5p->mtrprp_pfxtype,
                        d1r5p->mtrprp_caluded,
                        d1r5p->mtrprp_pfxcputy);
                    break;
                case 6:

                    break;
                case 7:

                    break;
                case 8:

                    break;
                case 9:
                    struct d1r9 *d1r9p;
                    d1r9p = (struct d1r9 *) b;
                    //  SQL QUERY R-9
                    sprintf(qbuf, "INSERT INTO d1r9 VALUES ('',FROM_UNIXTIME(%u),'%i','%i','%u','%u','%u','%u')",
			            utc,
                        d1r9p->mtrspr_interval,
                        d1r9p->mtrspr_hfrate,
                        d1r9p->mtrspr_sdomains,
                        d1r9p->ibm,
                        d1r9p->mtrspr_hdomains,
                        d1r9p->mtrspr_config);
                    break;
                case 10:
                    struct d1r10 *d1r10p;
                    d1r10p = (struct d1r10 *) b;
                    //  TOD 2 UTC
			        ttmp1 = (__eu64) tod2utc( (__eu64) d1r10p->mtrscm_caltod);
                    //  EBCDIC 2 ASCII
                    e2a(d1r10_txtp->mtrscm_calcmd, d1r10p->mtrscm_calbyct);
                    //  SQL QUERY R-10
                    sprintf(qbuf, "INSERT INTO d1r10 VALUES ('',FROM_UNIXTIME(%u),FROM_UNIXTIME(%u),'%u','%s')",
			            utc,
                        ttmp1,
                        d1r10p->mtrscm_calbyct,
                        d1r10_txtp->mtrscm_calcmd);
                    break;
                case 11:
                    //  TODO
                    struct d1r11 *d1r11;
                    d1r11p = (struct d1r11 *) b;
                    sprintf(qbuf, "INSERT INTO d1r11 VALUES ('',FROM_UNIXTIME(%u))",
			            utc);
                    break;
                case 12:
                    struct d1r12 *d1r12p;
                    d1r12p = (struct d1r12 *) b;
                    //  SQL QUERY R-12
                    sprintf(qbuf, "INSERT INTO d1r12 VALUES ('',FROM_UNIXTIME(%u))",
			            utc);
                    break;
                case 13:
                    struct d1r13 *d1r13p;
                    d1r13p = (struct d1r13 *) b;
                    //  SQL QUERY R-13
                    sprintf(qbuf, "INSERT INTO d1r13 VALUES ('',FROM_UNIXTIME(%u))",
			            utc);
                    break;
                case 14:

                    break;
                case 15:
                    struct d1r15 *d1r15p;
                    d1r15p = (struct d1r15 *) b;
                    //sprintf(qbuf, "INSERT INTO d1r13 VALUES ('',FROM_UNIXTIME(%u))",
			        //    utc);
                    break;
                case 16:
                    struct d1r16 *d1r16p;
                    d1r16p = (struct d1r16 *) b;
                    
                    break;
                case 17:
                    struct d1r17 *d1r17p;
                    d1r17p = (struct d1r17 *) b;
                    //  SQL QUERY R-17
                    sprintf(qbuf, "INSERT INTO d1r17 VALUES ('',FROM_UNIXTIME(%u), '%s','%s')",
			            utc,
                        d1r17p->mtrxsg_xstotalb,
                        d1r17p->mtrxsg_sysxtsiz);
                    break;
                case 18:
                    struct d1r18 *d1r18p;
                    d1r18p = (struct d1r18 *) b;
                    //  SQL QUERY R-18
                    sprintf(qbuf, "INSERT INTO d1r18 VALUES ('',FROM_UNIXTIME(%u), '%u','%u')",
			            utc,
                        d1r18p->mtrccc_cpucapab,
                        d1r18p->mtrccc_scpcapab);
                    break;
                case 19:
                    struct d1r19 *d1r19p;
                    d1r19p = (struct d1r19 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d1r19p->mtrqdc_vmduser, 8);
                    //  SQL QUERY R-19
                    sprintf(qbuf, "INSERT INTO d1r19 VALUES ('',FROM_UNIXTIME(%u),'%u','%s','%u','%u','%u','%u','%s','%u','%u','%u','%u','%u','%u','%lu','%lu','%lu','%lu','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
            		    utc,
                        d1r19p->mtrqdc_rdevdev,
                        d1r19p->mtrqdc_vmduser,
                        d1r19p->mtrqdc_vdevdev,
                        d1r19p->mtrqdc_qdiofmt,
                        d1r19p->mtrqdc_qdinpct,
                        d1r19p->mtrqdc_qdioutct,
                        d1r19p->mtrqdc_status,
                        d1r19p->mtrqdc_qdiocsgr,
                        d1r19p->mtrqdc_qdiocsgw,
                        d1r19p->mtrqdc_qdiocsgs,
                        d1r19p->mtrqdc_rdevvssr,
                        d1r19p->mtrqdc_rdevvssw,
                        d1r19p->mtrqdc_rdevvsss,
                        d1r19p->mtrqdc_bftoa,
                        d1r19p->mtrqdc_bytoa,
                        d1r19p->mtrqdc_bffra,
                        d1r19p->mtrqdc_byfra,
                        d1r19p->mtrqdc_rdevvsin,
                        d1r19p->mtrqdc_rdevvsir,
                        d1r19p->mtrqdc_rdevvsid,
                        d1r19p->mtrqdc_qsbsqbvm,
                        d1r19p->mtrqdc_qsbsqbpv,
                        d1r19p->mtrqdc_qsbeqbvm,
                        d1r19p->mtrqdc_qsbeqbpv,
                        d1r19p->mtrqdc_qsblock,
                        d1r19p->mtrqdc_qsbfobx,
                        d1r19p->mtrqdc_qsbolck,
                        d1r19p->mtrqdc_qsbsigwt,
                        d1r19p->mtrqdc_qsbsigrt,
                        d1r19p->mtrqdc_qsbsiglt,
                        d1r19p->mtrqdc_sumofpin,
                        d1r19p->mtrqdc_sumunpin);
                    break;
                case 20:
                    struct d1r20 *d1r20p;
                    d1r20p = (struct d1r20 *) b;
                    //  SQL QUERY R-20
                    sprintf(qbuf, "INSERT INTO d1r20 VALUES ('',FROM_UNIXTIME(%u), '%u','%u')",
			            utc,
                        d1r20p->mtrhpp_hppoolnm,
                        d1r20p->mtrhpp_hpptoken);
                    break;
                default:
                    unkn_flag = true;
                    break;
            }
            break;
        case 2:
            switch (r) {
                case 1:
                    struct d2r1 *d2r1p;
                    d2r1p = (struct d2r1 *) b;

                    e2a(d2r1p->sclrdb_vmduser, 8);
                    //  SQL QUERY R-1
                    sprintf(qbuf, "INSERT INTO d2r1 VALUES ('',FROM_UNIXTIME(%u),'%s','%u','%u')",
                        utc,
                        d2r1p->sclrdb_vmduser,
                        d2r1p->sclrdb_calflags,
                        d2r1p->sclrdb_rdevsid);
                    break;
                case 2:
                    struct d2r2 *d2r2p;
                    d2r2p = (struct d2r2 *) b;

                    e2a(d2r2p->sclrdc_vmduser, 8);
                    //  SQL QUERY R-2
                    sprintf(qbuf, "INSERT INTO d2r2 VALUES ('',FROM_UNIXTIME(%u),'%s','%u','','%u','%u')",
                        utc,
                        d2r2p->sclrdc_vmduser,
                        d2r2p->sclrdc_calflags,
                        d2r2p->sclrdc_rdevsid,
                        d2r2p->sclrdc_calbyct);
                    break;
                case 3:
                    struct d2r3 *d2r3p;
                    d2r3p = (struct d2r3 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d2r3p->sclwrr_vmduser, 8);
                    //  SQL QUERY R-3
                    sprintf(qbuf, "INSERT INTO d2r3 VALUES ('',FROM_UNIXTIME(%u),'%s','%u','%u','%u')",
			            utc,
                        d2r3p->sclwrr_vmduser,
                        d2r3p->sclwrr_calflags,
                        d2r3p->sclwrr_rdevsid,
                        d2r3p->sclwrr_calbyct);
                    break;
                case 4:

                    break;
                case 5:

                    break;
                case 6:

                    break;
                case 7:

                    break;
                case 8:

                    break;
                case 9:
                    struct d2r9 *d2r9p;
                    d2r9p = (struct d2r9 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d2r9p->sclshr_vmduser, 8);
                    //  SQL QUERY R-9
                    sprintf(qbuf, "INSERT INTO d2r9 VALUES ('',FROM_UNIXTIME(%u),'%s','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d2r9p->sclshr_vmduser,
                        d2r9p->sclshr_vmdrelsh,
                        d2r9p->sclshr_vmdabssh,
                        d2r9p->sclshr_calsharf,
                        d2r9p->sclshr_vmdmxshr,
                        d2r9p->sclshr_vmdcfgem,
                        d2r9p->sclshr_vmdpust);
                    break;
                case 10:
                    struct d2r10 *d2r10p;
                    d2r10p = (struct d2r10 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d2r10p->sclsqd_vmduser, 8);
                    //  SQL QUERY R-10
                    sprintf(qbuf, "INSERT INTO d2r10 VALUES ('',FROM_UNIXTIME(%u),'%s','%u')",
			            utc,
			            d2r10p->sclsqd_vmduser,
                        d2r10p->sclsqd_calflag1);
                    break;
                case 11:
                    struct d2r11 *d2r11p;
                    d2r11p = (struct d2r11 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d2r11p->scliop_vmduser, 8);
                    // SQL QUERY R-11
                    sprintf(qbuf, "INSERT INTO d2r11 VALUES ('',FROM_UNIXTIME(%u),'%s','%u','%u','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d2r11p->scliop_vmduser,
                        d2r11p->scliop_ipqupr1,
                        d2r11p->scliop_newrqlo,
                        d2r11p->scliop_newrqhi,
                        d2r11p->scliop_ipqx0,
                        d2r11p->scliop_sysiopq,
                        d2r11p->scliop_sysiopqh,
                        d2r11p->scliop_sysioplo,
                        d2r11p->scliop_sysiophi);
                    break;
                case 12:
                    struct d2r12 *d2r12p;
                    d2r12p = (struct d2r12 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d2r12p->sclsca_vmduser, 8);
                    //  SQL QUERY R-12
                    sprintf(qbuf, "INSERT INTO d2r12 VALUES ('',FROM_UNIXTIME(%u),'%s','%u','%u')",
			            utc,
                        d2r12p->sclsca_vmduser,
                        d2r12p->sclsca_vmdcfgem,
                        d2r12p->sclsca_vmdpust);
                    break;

                default:
                    unkn_flag = true;
                    break;
            }
            break;
        case 3:
            switch (r) {
                case 1:
                    struct d3r1 *d3r1p;
                    d3r1p = (struct d3r1 *) b;
                    //  SQL QUERY R-1
                    sprintf(qbuf, "INSERT INTO d3r1 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%s','%s','%s','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%s','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d3r1p->storsg_calssubt,
                        d3r1p->storsg_rsasavfr,
                        d3r1p->storsg_rsamaxpp,
                        d3r1p->storsg_rsacplok,
                        d3r1p->storsg_rsaavllt,
                        d3r1p->storsg_rsaavlht,
                        d3r1p->storsg_xstbprct,
                        d3r1p->storsg_xstsrgct,
                        d3r1p->storsg_xstmrabi,
                        d3r1p->storsg_xstsrabi,
                        d3r1p->storsg_xstsrsct,
                        d3r1p->storsg_calptrrt,
                        d3r1p->storsg_calcaafp,
                        d3r1p->storsg_calascut,
                        d3r1p->storsg_rsasxcpl,
                        d3r1p->storsg_rsasxcla,
                        d3r1p->storsg_rsaavlhg,
                        d3r1p->storsg_rsaavllg,
                        d3r1p->storsg_rsacplkg,
                        d3r1p->storsg_calssubg,
                        d3r1p->storsg_rsarsvsy,
                        d3r1p->storsg_rsacallt,
                        d3r1p->storsg_rsacalmt,
                        d3r1p->storsg_rsacalut,
                        d3r1p->storsg_rsaafsdw,
                        d3r1p->storsg_rsaafsdb,
                        d3r1p->storsg_rsaafsiu,
                        d3r1p->storsg_rsaafsib,
                        d3r1p->storsg_rsavcbdw,
                        d3r1p->storsg_rsavcbdb,
                        d3r1p->storsg_rsavcbiu,
                        d3r1p->storsg_rsavcbib,
                        d3r1p->storsg_rsavfsdw,
                        d3r1p->storsg_rsavfsiu,
                        d3r1p->storsg_rsa2gdct,
                        d3r1p->storsg_rsafrqwt,
                        d3r1p->storsg_rsafrrda,
                        d3r1p->storsg_rsafrrdc,
                        d3r1p->storsg_rsastlwt,
                        d3r1p->storsg_rsaswg2g,
                        d3r1p->storsg_rsafvmud,
                        d3r1p->storsg_rsafvmub,
                        d3r1p->storsg_rsavmxfr,
                        d3r1p->storsg_rsavmxfb,
                        d3r1p->storsg_rsavmxud,
                        d3r1p->storsg_rsavmxub,
                        d3r1p->storsg_rsasysfr,
                        d3r1p->storsg_rsasysfb,
                        d3r1p->storsg_rsasysud,
                        d3r1p->storsg_rsasysub,
                        d3r1p->storsg_rsaplpct,
                        d3r1p->storsg_rsaplpcb,
                        d3r1p->storsg_rsanpgct,
                        d3r1p->storsg_rsanpghi,
                        d3r1p->storsg_rsanolkl,
                        d3r1p->storsg_rsanolka,
                        d3r1p->storsg_rsasxnop,
                        d3r1p->storsg_rsapptps,
                        d3r1p->storsg_rsapptpf,
                        d3r1p->storsg_rsapptcs,
                        d3r1p->storsg_rsablkgc,
                        d3r1p->storsg_rsafrqmw,
                        d3r1p->storsg_rsafrqdf,
                        d3r1p->storsg_rsafrqdl,
                        d3r1p->storsg_rsaalfmf,
                        d3r1p->storsg_rsaavclt,
                        d3r1p->storsg_rsaavcht,
                        d3r1p->storsg_rsaavclg,
                        d3r1p->storsg_rsaavchg,
                        d3r1p->storsg_rsaemlo,
                        d3r1p->storsg_rsaemhi,
                        d3r1p->storsg_rsaemcpc,
                        d3r1p->storsg_rsaemerg,
                        d3r1p->storsg_rsaemblo,
                        d3r1p->storsg_rsaempty,
                        d3r1p->storsg_rsaemdfr,
                        d3r1p->storsg_rsaswpwt,
                        d3r1p->storsg_rsaswp2g);
                    break;
                case 2:
                    struct d3r2 *d3r2p;
                    d3r2p = (struct d3r2 *) b;
                    //  SQL QUERY R-2
                    sprintf(qbuf, "INSERT INTO d3r3 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%s','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d3r2p->storsp_pfxcpuad,
                        d3r2p->storsp_plspread,
                        d3r2p->storsp_plspnew,
                        d3r2p->storsp_pfxclear,
                        d3r2p->storsp_pfxptrct,
                        d3r2p->storsp_plsreles,
                        d3r2p->storsp_plsretfr,
                        d3r2p->storsp_plsrelfr,
                        d3r2p->storsp_plsalnct,
                        d3r2p->storsp_plsstlwt,
                        d3r2p->storsp_plsltd1,
                        d3r2p->storsp_plsdorm1,
                        d3r2p->storsp_plsshar1,
                        d3r2p->storsp_plselig1,
                        d3r2p->storsp_plsdisp1,
                        d3r2p->storsp_plsltd2,
                        d3r2p->storsp_plsdorm2,
                        d3r2p->storsp_plselig2,
                        d3r2p->storsp_plsdisp2,
                        d3r2p->storsp_plsshare,
                        d3r2p->storsp_plsdorme,
                        d3r2p->storsp_plselige,
                        d3r2p->storsp_plsdispe,
                        d3r2p->storsp_plsltdp1,
                        d3r2p->storsp_plsdrmp1,
                        d3r2p->storsp_plsshrp1,
                        d3r2p->storsp_plsdspp1,
                        d3r2p->storsp_plselgp1,
                        d3r2p->storsp_plsltdp2,
                        d3r2p->storsp_plsdrmp2,
                        d3r2p->storsp_plsshrp2,
                        d3r2p->storsp_plsdspp2,
                        d3r2p->storsp_plselgp2,
                        d3r2p->storsp_plsdrmpe,
                        d3r2p->storsp_plsshrpe,
                        d3r2p->storsp_plsdsppe,
                        d3r2p->storsp_plselgpe,
                        d3r2p->storsp_plspgdrd,
                        d3r2p->storsp_plspgdwt,
                        d3r2p->storsp_plsalncg,
                        d3r2p->storsp_plsretfg,
                        d3r2p->storsp_plsfsprb,
                        d3r2p->storsp_plsfspra,
                        d3r2p->storsp_plsfsctb,
                        d3r2p->storsp_plsfscta,
                        d3r2p->storsp_plsfretb,
                        d3r2p->storsp_plsfreta,
                        d3r2p->storsp_plsfssgb,
                        d3r2p->storsp_plsfssga,
                        d3r2p->storsp_plsfspgb,
                        d3r2p->storsp_plsfspga,
                        d3r2p->storsp_plsbgcnt,
                        d3r2p->storsp_plsfgctm,
                        d3r2p->storsp_plsfgcnt,
                        d3r2p->storsp_plsfobem,
                        d3r2p->storsp_plsfssra,
                        d3r2p->storsp_plsfssrb,
                        d3r2p->storsp_plsvatcl,
                        d3r2p->storsp_plsupage,
                        d3r2p->storsp_plsvpage,
                        d3r2p->storsp_plspcpag,
                        d3r2p->storsp_plspupag,
                        d3r2p->storsp_plsuprec,
                        d3r2p->storsp_plsessa,
                        d3r2p->storsp_plsltdpe,
                        d3r2p->storsp_plsasfcl,
                        d3r2p->storsp_plsasfcg,
                        d3r2p->storsp_pfxcputy);
                    break;
                case 3:
                    struct d3r3 *d3r3p;
                    d3r3p = (struct d3r3 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d3r3p->stoshr_sntname, 8);
                    //  SQL QUERY R-3
                    sprintf(qbuf, "INSERT INTO d3r3 VALUES ('',FROM_UNIXTIME(%u),'%s','%i','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d3r3p->stoshr_sntname,
                        d3r3p->stoshr_sdfidnum,
                        d3r3p->stoshr_sdfcltim,
                        d3r3p->stoshr_sntusrsh,
                        d3r3p->stoshr_sntusrex,
                        d3r3p->stoshr_ascctprs,
                        d3r3p->stoshr_sntstrct,
                        d3r3p->stoshr_sntndtct,
                        d3r3p->stoshr_asccspst,
                        d3r3p->stoshr_ascptrsh,
                        d3r3p->stoshr_asccspgr,
                        d3r3p->stoshr_asccspgw,
                        d3r3p->stoshr_asccsxrd,
                        d3r3p->stoshr_asccsxwt,
                        d3r3p->stoshr_asccsmig,
                        d3r3p->stoshr_ascctpgs,
                        d3r3p->stoshr_ascctxbk,
                        d3r3p->stoshr_ascctprg,
                        d3r3p->stoshr_aschllc,
                        d3r3p->stoshr_aschlrc);
                    break;
                case 4:
                    struct d3r4 *d3r4p;
                    d3r4p = (struct d3r4 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d3r4p->stoasp_calvser, 6);
                    //  SQL QUERY R-4
                    sprintf(qbuf, "INSERT INTO d3r4 VALUES ('',FROM_UNIXTIME(%u),'%s','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%s','%u','%u','%u','%u','%u')",
			            utc,
                        d3r4p->stoasp_calvser,
                        d3r4p->stoasp_rdevdev,
                        d3r4p->stoasp_rdevsid,
                        d3r4p->stoasp_calspool,
                        d3r4p->stoasp_calpage,
                        d3r4p->stoasp_expctsrd,
                        d3r4p->stoasp_expctswr,
                        d3r4p->stoasp_expctprd,
                        d3r4p->stoasp_expctpwr,
                        d3r4p->stoasp_expcurqc,
                        d3r4p->stoasp_expctacp,
                        d3r4p->stoasp_expctusi,
                        d3r4p->stoasp_scmssch,
                        d3r4p->stoasp_calflag1,
                        d3r4p->stoasp_rdevdran,
                        d3r4p->stoasp_expcont,
                        d3r4p->stoasp_expdevst,
                        d3r4p->stoasp_expmload,
                        d3r4p->stoasp_cpvlokat,
                        d3r4p->stoasp_cpvalocd,
                        d3r4p->stoasp_scgssch);
                    break;
                case 5:
                    struct d3r5 *d3r5p;
                    d3r5p = (struct d3r5 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d3r5p->stoshs_sdffn, 8);
                    e2a(d3r5p->stoshs_sdfft, 8);
                    e2a(&d3r5p->stoshs_sdfclass, 1);
                    //  SQL QUERY R-5
                    sprintf(qbuf, "INSERT INTO d3r5 VALUES ('',FROM_UNIXTIME(%u),'%s','%s','%u','%i','%c')",
			            utc,
                        d3r5p->stoshs_sdffn,
                        d3r5p->stoshs_sdfft,
                        d3r5p->stoshs_sdfcltim,
                        d3r5p->stoshs_sdfidnum,
                        d3r5p->stoshs_sdfclass);
                    break;
                case 6:
                    struct d3r6 *d3r6p;
                    d3r6p = (struct d3r6 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d3r6p->stoshp_sdffn, 8);
                    e2a(d3r6p->stoshp_sdfft, 8);
                    e2a(&d3r6p->stoshp_sdfclass, 1);
                    //  SQL QUERY R-6
                    sprintf(qbuf, "INSERT INTO d3r6 VALUES ('',FROM_UNIXTIME(%u),'%s','%s','%u','%i','%c')",
			            utc,
                        d3r6p->stoshp_sdffn,
                        d3r6p->stoshp_sdfft,
                        d3r6p->stoshp_sdfcltim,
                        d3r6p->stoshp_sdfidnum,
                        d3r6p->stoshp_sdfclass);
                    break;
                case 7:
                    struct d3r7 *d3r7p;
                    d3r7p = (struct d3r7 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d3r7p->stoatc_cpvolser, 6);
                    e2a(d3r7p->stoatc_caltype, 4);
                    //  SQL QUERY R-7
                    sprintf(qbuf, "INSERT INTO d3r7 VALUES ('',FROM_UNIXTIME(%u),'%s','%u','%s','%i','%i','%i','%u','%u')",
			            utc,
                        d3r7p->stoatc_cpvolser,
                        d3r7p->stoatc_calflags,
                        d3r7p->stoatc_caltype,
                        d3r7p->stoatc_calcylno,
                        d3r7p->stoatc_calstart,
                        d3r7p->stoatc_rdcpcyl,
                        d3r7p->stoatc_rdevsid,
                        d3r7p->stoatc_rdevdev);
                    break;
                case 8:
                    struct d3r8 *d3r8p;
                    d3r8p = (struct d3r8 *) b;
                    //  SQL QUERY R-8
                    sprintf(qbuf, "INSERT INTO d3r8 VALUES ('',FROM_UNIXTIME(%u),'%s','%s','%s')",
			            utc,
                        d3r8p->stobpg_pgdbr_tbl,
                        d3r8p->stobpg_pgdbm_tbl,
                        d3r8p->stobpg_pgdbs_tbl);
                    break;
                case 9:
                    struct d3r9 *d3r9p;
                    d3r9p = (struct d3r9 *) b;
                    //  SQL QUERY R-9
                    sprintf(qbuf, "INSERT INTO d3r9 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%s','%u','%u','%u','%u','%u','%u','%u','%s'",
			            utc,
                        d3r9p->stoxsg_xstmigs,
                        d3r9p->stoxsg_xstblkdm,
                        d3r9p->stoxsg_xstsumag,
                        d3r9p->stoxsg_xstblkcy,
                        d3r9p->stoxsg_xstblksh,
                        d3r9p->stoxsg_xstblksy,
                        d3r9p->stoxsg_xstlothr,
                        d3r9p->stoxsg_xstcycls,
                        d3r9p->stoxsg_xstcpdal,
                        d3r9p->stoxsg_xstguest,
                        d3r9p->stoxsg_xstnoio);
                    break;
                case 10:
                    struct d3r10 *d3r10p;
                    d3r10p = (struct d3r10 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d3r10p->stoxsu_vmduser, 8);
                    //  SQL QUERY R-10
                    sprintf(qbuf, "INSERT INTO d3r10 VALUES ('',FROM_UNIXTIME(%u),'%s','%u','%u','%u')",
			            utc,
                        d3r10p->stoxsu_vmduser,
                        d3r10p->stoxsu_calxstor,
                        d3r10p->stoxsu_calorgin,
                        d3r10p->stoxsu_calxslim);
                    break;
                case 11:
                    struct d3r11 *d3r11p;
                    d3r11p = (struct d3r11 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d3r11p->stoass_cpvolser, 6);
                    //  SQL QUERY R-11
                    sprintf(qbuf, "INSERT INTO d3r11 VALUES ('',FROM_UNIXTIME(%u),'%s','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d3r11p->stoass_cpvolser,
                        d3r11p->stoass_rdevsid,
                        d3r11p->stoass_expctsrd,
                        d3r11p->stoass_expctswr,
                        d3r11p->stoass_expctprd,
                        d3r11p->stoass_expctpwr,
                        d3r11p->stoass_expcurqc,
                        d3r11p->stoass_expctacp,
                        d3r11p->stoass_expctusi,
                        d3r11p->stoass_scmssch,
                        d3r11p->stoass_scgssch,
                        d3r11p->stoass_rdevdev);
                    break;
                case 12:
                    struct d3r12 *d3r12p;
                    d3r12p = (struct d3r12 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d3r12p->stoasc_ascusrid, 8);
                    e2a(d3r12p->stoasc_ascname, 24);
                    //  SQL QUERY R-12
                    sprintf(qbuf, "INSERT INTO d3r12 VALUES ('',FROM_UNIXTIME(%u),'%s','%s','%u','%s','%s','%s')",
			            utc,
                        d3r12p->stoasc_ascusrid,
                        d3r12p->stoasc_ascname,
                        d3r12p->stoasc_ascssize,
                        d3r12p->stoasc_ascdefsz,
                        d3r12p->stoasc_caldefhi,
                        d3r12p->stoasc_caldeflo);
                    break;
                case 13:
                    struct d3r13 *d3r13p;
                    d3r13p = (struct d3r13 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d3r13p->stoasd_ascusrid, 8);
                    e2a(d3r13p->stoasd_ascname, 24);
                    //  SQL QUERY R-13
                    sprintf(qbuf, "INSERT INTO d3r13 VALUES ('',FROM_UNIXTIME(%u),'%s','%s')",
			            utc,
                        d3r13p->stoasd_ascusrid,
                        d3r13p->stoasd_ascname);
                    break;
                case 14:
                    struct d3r14 *d3r14p;
                    d3r14p = (struct d3r14 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d3r14p->stoasi_ascusrid, 8);
                    e2a(d3r14p->stoasi_ascname, 24);
                    e2a(d3r14p->stoasi_ascdefsz, 8);
                    e2a(d3r14p->stoasi_caldefhi, 4);
                    e2a(d3r14p->stoasi_caldeflo, 4);
                    e2a(d3r14p->stoasi_ascctplka, 8);
                    //  SQL QUERY R-14
                    sprintf(qbuf, "INSERT INTO d3r14 VALUES ('',FROM_UNIXTIME(%u),'%s','%s','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%s','%s','%s','%u','%u','%u','%u','%s')",
			            utc,
                        d3r14p->stoasi_ascusrid,
                        d3r14p->stoasi_ascname,
                        d3r14p->stoasi_calstate,
                        d3r14p->stoasi_ascctspi,
                        d3r14p->stoasi_ascctprs,
                        d3r14p->stoasi_asccspst,
                        d3r14p->stoasi_asccspgr,
                        d3r14p->stoasi_asccspgw,
                        d3r14p->stoasi_asccsxrd,
                        d3r14p->stoasi_asccsxwt,
                        d3r14p->stoasi_asccsmig,
                        d3r14p->stoasi_ascctplk,
                        d3r14p->stoasi_ascctpgs,
                        d3r14p->stoasi_ascctxbk,
                        d3r14p->stoasi_ascssize,
                        d3r14p->stoasi_ascdefsz,
                        d3r14p->stoasi_caldefhi,
                        d3r14p->stoasi_caldeflo,
                        d3r14p->stoasi_ascmvb2g,
                        d3r14p->stoasi_ascctprg,
                        d3r14p->stoasi_aschllc,
                        d3r14p->stoasi_aschlrc,
                        d3r14p->stoasi_ascctplka);
                    break;
                case 15:
                    struct d3r15 *d3r15p;
                    d3r15p = (struct d3r15 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d3r15p->stoshl_sdffn, 8);
                    e2a(d3r15p->stoshl_sdfft, 8);
                    e2a(&d3r15p->stoshl_sdfclass, 1);
                    //  SQL QUERY R-15
                    sprintf(qbuf, "INSERT INTO d3r15 VALUES ('',FROM_UNIXTIME(%u),'%s','%s','%u','%i','%c')",
			            utc,
                        d3r15p->stoshl_sdffn,
                        d3r15p->stoshl_sdfft,
                        d3r15p->stoshl_sdfcltim,
                        d3r15p->stoshl_sdfidnum,
                        d3r15p->stoshl_sdfclass);
                    break;
                case 16:
                    struct d3r16 *d3r16p;
                    d3r16p = (struct d3r16 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d3r16p->stoshd_sdffn, 8);
                    e2a(d3r16p->stoshd_sdfft, 8);
                    e2a(&d3r16p->stoshd_sdfclass, 1);
                    //  SQL QUERY R-16
                    sprintf(qbuf, "INSERT INTO d3r16 VALUES ('',FROM_UNIXTIME(%u),'%s','%s','%u','%i','%c','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d3r16p->stoshd_sdffn,
                        d3r16p->stoshd_sdfft,
                        d3r16p->stoshd_sdfcltim,
                        d3r16p->stoshd_sdfidnum,
                        d3r16p->stoshd_sdfclass,
                        d3r16p->stoshd_ascctprs,
                        d3r16p->stoshd_sntstrct,
                        d3r16p->stoshd_sntndtct,
                        d3r16p->stoshd_asccspst,
                        d3r16p->stoshd_ascptrsh,
                        d3r16p->stoshd_asccspgr,
                        d3r16p->stoshd_asccspgw,
                        d3r16p->stoshd_asccsxrd,
                        d3r16p->stoshd_asccsxwt,
                        d3r16p->stoshd_asccsmig,
                        d3r16p->stoshd_ascctpgs,
                        d3r16p->stoshd_ascctprg,
                        d3r16p->stoshd_aschllc,
                        d3r16p->stoshd_aschlrc);
                    break;
                case 17:
                    struct d3r17 *d3r17p;
                    d3r17p = (struct d3r17 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d3r17p->stovdk_mdiouser, 8);
                    e2a(d3r17p->stovdk_qdisname, 24);
                    //  SQL QUERY R-17
                    sprintf(qbuf, "INSERT INTO d3r17 VALUES ('',FROM_UNIXTIME(%u),'%s','%s','%u','%u','%u','%u','%u')",
			            utc,
                        d3r17p->stovdk_mdiouser,
                        d3r17p->stovdk_qdisname,
                        d3r17p->stovdk_mdiovdev,
                        d3r17p->stovdk_calflag,
                        d3r17p->stovdk_mdilinks,
                        d3r17p->stovdk_calsize,
                        d3r17p->stovdk_qdiiocnt);
                    break;
                case 18:
                    struct d3r18 *d3r18p;
                    d3r18p = (struct d3r18 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d3r18p->stoscs_poolname, 8);
                    //  SQL QUERY R-18
                    sprintf(qbuf, "INSERT INTO d3r18 VALUES ('',FROM_UNIXTIME(%u),'%s','%u','%u','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d3r18p->stoscs_poolname,
                        d3r18p->stoscs_frxroot,
                        d3r18p->stoscs_frxplen,
                        d3r18p->stoscs_malloc,
                        d3r18p->stoscs_mallocf,
                        d3r18p->stoscs_frees,
                        d3r18p->stoscs_freef,
                        d3r18p->stoscs_current,
                        d3r18p->stoscs_maxalloc);
                    break;
                case 19:
                    struct d3r19 *d3r19p;
                    d3r19p = (struct d3r19 *) b;
                    //  SQL QUERY R-19
                    sprintf(qbuf, "INSERT INTO d3r19 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d3r19p->stosxg_rsasxuot,
                        d3r19p->stosxg_rsasxctg,
                        d3r19p->stosxg_rsasxcpl,
                        d3r19p->stosxg_rsasxpct,
                        d3r19p->stosxg_rsasxdct,
                        d3r19p->stosxg_rsasxdca,
                        d3r19p->stosxg_rsasxdpa,
                        d3r19p->stosxg_rsasxdpb,
                        d3r19p->stosxg_rsasxdfa,
                        d3r19p->stosxg_rsasxdfb,
                        d3r19p->stosxg_rsasxrda,
                        d3r19p->stosxg_rsasxrdc,
                        d3r19p->stosxg_rsasxamx,
                        d3r19p->stosxg_rsasxbmx,
                        d3r19p->stosxg_rsasxqmn,
                        d3r19p->stosxg_rsasxqra,
                        d3r19p->stosxg_rsasxrpm);
                    break;
                case 20:
                    struct d3r20 *d3r20p;
                    d3r20p = (struct d3r20 *) b;
                    //  SQL QUERY R-20
                    sprintf(qbuf, "INSERT INTO d3r20 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d3r20p->stosxp_pfxcpuad,
                        d3r20p->stosxp_plssutkc,
                        d3r20p->stosxp_plssurtc,
                        d3r20p->stosxp_plssupuc,
                        d3r20p->stosxp_plssuqmt,
                        d3r20p->stosxp_plssatkc,
                        d3r20p->stosxp_plssartc,
                        d3r20p->stosxp_plssapuc,
                        d3r20p->stosxp_plssaqmt,
                        d3r20p->stosxp_plssbtkc,
                        d3r20p->stosxp_plssbrtc,
                        d3r20p->stosxp_plssbpuc,
                        d3r20p->stosxp_plssbqmt,
                        d3r20p->stosxp_plssxals,
                        d3r20p->stosxp_plssxadc,
                        d3r20p->stosxp_plssxasc,
                        d3r20p->stosxp_plsspndp,
                        d3r20p->stosxp_plsspndf,
                        d3r20p->stosxp_plsspgpd,
                        d3r20p->stosxp_plsspgfd,
                        d3r20p->stosxp_plsspgbd,
                        d3r20p->stosxp_plsspdqc,
                        d3r20p->stosxp_plssxipc,
                        d3r20p->stosxp_plssxnst,
                        d3r20p->stosxp_plssxafc,
                        d3r20p->stosxp_plssxcsp,
                        d3r20p->stosxp_plssxald,
                        d3r20p->stosxp_pfxcputy);
                    break;

                default:
                    unkn_flag = true;
                    break;
            }
            break;
        case 4:
            switch (r) {
                case 1:
                    
                    break;
                case 2:
                    
                    break;
                case 3:
                    
                    break;
                case 4:
                    
                    break;
                case 5:
                    struct d4r5 *d4r5p;
                    d4r5p = (struct d4r5 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d4r5p->usedfc_vmduser, 8);
                    //  SQL QUERY R-5
                    sprintf(qbuf, "INSERT INTO d4r5 VALUES ('',FROM_UNIXTIME(%u),'%s','%u','%u','%u','%u','%u')",
			            utc,
			            d4r5p->usedfc_vmduser,
                        d4r5p->usedfc_vmdcpuad,
                        d4r5p->usedfc_vmdputyp,
                        d4r5p->usedfc_vmdcfgem,
                        d4r5p->usedfc_vmdpust,
                        d4r5p->usedfc_oldputyp);
                    break;
                case 6:
                    struct d4r6 *d4r6p;
                    d4r6p = (struct d4r6 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d4r6p->usedtc_vmduser, 8);
                    //  SQL QUERY R-6
                    sprintf(qbuf, "INSERT INTO d4r6 VALUES ('',FROM_UNIXTIME(%u),'%s','%u','%u')",
			            utc,
                        d4r6p->usedtc_vmduser,
                        d4r6p->usedtc_vmdcpuad,
                        d4r6p->usedtc_vmdputyp);
                    break;
                case 7:
                    struct d4r7 *d4r7p;
                    d4r7p = (struct d4r7 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d4r7p->userdc_vmduser, 8);
                    //  SQL QUERY R-7
                    sprintf(qbuf, "INSERT INTO d4r7 VALUES ('',FROM_UNIXTIME(%u),'%s','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d4r7p->userdc_vmduser,
                        d4r7p->userdc_vmdcpuad,
                        d4r7p->userdc_newcpuad,
                        d4r7p->userdc_vmdputyp,
                        d4r7p->userdc_newputyp,
                        d4r7p->userdc_vmdcfgem,
                        d4r7p->userdc_vmdpust);
                    break;
                case 8:
                    
                    break;
                case 9:
                    
                    break;
                case 10:
                    struct d4r10 *d4r10p;
                    d4r10p = (struct d4r10 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d4r10p->useite_vmduser, 8);
			        e2a(d4r10p->useite_vmdsvmid, 8);
                    //  SQL QUERY R-10
                    sprintf(qbuf, "INSERT INTO d4r10 VALUES ('',FROM_UNIXTIME(%u),'%s','%u','%u','%u','%s','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%d','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
                        utc, 
                        d4r10p->useite_vmduser,
                        d4r10p->useite_vmdcpuad,
                        d4r10p->useite_vmdslcnt,
                        d4r10p->useite_vmdsvmfx,
                        d4r10p->useite_vmdsvmid,
                        d4r10p->useite_vmdsvmwt,
                        d4r10p->useite_vmdsvmw2,
                        d4r10p->useite_vmdsvmwt,
                        d4r10p->useite_vmdrdycm,
                        d4r10p->useite_vmdsvmwt,
                        d4r10p->useite_calflag1,
                        d4r10p->useite_hfquct,
                        d4r10p->useite_hfdisp0,
                        d4r10p->useite_hfdisp1,
                        d4r10p->useite_hfdisp2,
                        d4r10p->useite_hfdisp3,
                        d4r10p->useite_hfelig0,
                        d4r10p->useite_hfelig1,
                        d4r10p->useite_hfelig2,
                        d4r10p->useite_hfelig3,
                        d4r10p->useite_hfstct,
                        d4r10p->useite_hftidl,
                        d4r10p->useite_hftsvm,
                        d4r10p->useite_hfiowt,
                        d4r10p->useite_hfcfwt,
                        d4r10p->useite_hfsimwt,
                        d4r10p->useite_hfwtpag,
                        d4r10p->useite_hfcpuwt,
                        d4r10p->useite_hfcpurn,
                        d4r10p->useite_hfesvm,
                        d4r10p->useite_hfload,
                        d4r10p->useite_hfdorm,
                        d4r10p->useite_hfdsvm,
                        d4r10p->useite_hfothr,
                        d4r10p->useite_vmdcntid,
                        d4r10p->useite_vmdctidl,
                        d4r10p->useite_vmddfrwk,
                        d4r10p->useite_vmdstate,
                        d4r10p->useite_calostat,
                        d4r10p->useite_calrstat,
                        d4r10p->useite_vmdcprmd_q0,
                        d4r10p->useite_vmdcprmd_q1,
                        d4r10p->useite_vmdcprmd_q2,
                        d4r10p->useite_vmdcprmd_q3,
                        d4r10p->useite_vmdcwsgd_q0,
                        d4r10p->useite_vmdcwsgd_q1,
                        d4r10p->useite_vmdcwsgd_q2,
                        d4r10p->useite_vmdcwsgd_q3,
                        d4r10p->useite_vmdcetsd_q0,
                        d4r10p->useite_vmdcetsd_q1,
                        d4r10p->useite_vmdcetsd_q2,
                        d4r10p->useite_vmdcetsd_q3,
                        d4r10p->useite_vmdcidld_q0,
                        d4r10p->useite_vmdcidld_q1,
                        d4r10p->useite_vmdcidld_q2,
                        d4r10p->useite_vmdcidld_q3,
                        d4r10p->useite_hfioact,
                        d4r10p->useite_hfllist,
                        d4r10p->useite_hfpgact,
                        d4r10p->useite_vmdputyp,
                        d4r10p->useite_vmdcfgem,
                        d4r10p->useite_vmdpust);
                    break;                    
                default:
                    unkn_flag = true;
                    break;
            }
            break;
        case 5:
            switch (r) {
                case 1:
                    struct d5r1 *d5r1p;
                    d5r1p = (struct d5r1 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d5r1p->prcvon_pfxidmdl, 8);
			        e2a(d5r1p->prcvon_pfxidser, 8);
                    //  SQL QUERY R-1
                    sprintf(qbuf, "INSERT INTO d5r1 VALUES ('',FROM_UNIXTIME(%u),'%u','%s','%s','%u','%u')",
                        utc, 
                        d5r1p->prcvon_pfxcpuad,
                        d5r1p->prcvon_pfxidmdl,
                        d5r1p->prcvon_pfxidser,
                        d5r1p->prcvon_pfxidver,
                        d5r1p->prcvon_pfxcputy);
                    break;
                case 2:
                    struct d5r2 *d5r2p;
                    d5r2p = (struct d5r2 *) b;
                    //  SQL QUERY R-2
                    sprintf(qbuf, "INSERT INTO d5r2 VALUES ('',FROM_UNIXTIME(%u),'%u')",
                        utc,
                        d5r2p->prcvof_pfxcpuad);
                    break;
                case 3:
                    struct d5r3 *d5r3p;
                    d5r3p = (struct d5r3 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d5r3p->prcprp_caluded, 8);
                    //  SQL QUERY R-3
                    sprintf(qbuf, "INSERT INTO d5r3 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%s','%u','%u','%s','%u')",
                        utc,
                        d5r3p->prcprp_pfxcpuad,
                        d5r3p->prcprp_pfxdspcs,
                        d5r3p->prcprp_plsdspcm,
                        d5r3p->prcprp_dsvmaxus,
                        d5r3p->prcprp_hfcount,
                        d5r3p->prcprp_hfuserz,
                        d5r3p->prcprp_hfuserc,
                        d5r3p->prcprp_caluded,
                        d5r3p->prcprp_pfxtype,
                        d5r3p->prcprp_hfuserm,
                        d5r3p->prcprp_plsstlct,
                        d5r3p->prcprp_pfxcputy);
                    break;
                case 4:

                    break;
                case 5:
                    //  no longer available
                    break;
                case 6:
                    struct d5r6 *d5r6p;
                    d5r6p = (struct d5r6 *) b;
                    //  SQL QUERY R-6
                    sprintf(qbuf, "INSERT INTO d5r6 VALUES ('',FROM_UNIXTIME(%u),'%u','%u')",
                        utc,
                        d5r6p->prccfn_pfxcpuad,
                        d5r6p->prccfn_pcccsu);
                    break;
                case 7:
                    struct d5r7 *d5r7p;
                    d5r7p = (struct d5r7 *) b;
                    //  SQL QUERY R-7
                    sprintf(qbuf, "INSERT INTO d5r7 VALUES ('',FROM_UNIXTIME(%u),'%u','%u')",
                        utc,
                        d5r7p->prccff_pfxcpuad,
                        d5r7p->prccff_pcccsu);
                    break;
                case 8:
                    struct d5r8 *d5r8p;
                    d5r8p = (struct d5r8 *) b;
                    //  SQL QUERY R-8
                    sprintf(qbuf, "INSERT INTO d5r8 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%s','%s','%s','%s','%s','%s','%s','%s')",
                        utc,
                        d5r8p->prciop_csciopid,
                        d5r8p->prciop_cscvblbc,
                        d5r8p->prciop_cscvblic,
                        d5r8p->prciop_cscvblsc,
                        d5r8p->prciop_cscvblpi,
                        d5r8p->prciop_cscvblcb,
                        d5r8p->prciop_cscvblsb,
                        d5r8p->prciop_cscvblub,
                        d5r8p->prciop_cscvbldb,
                        d5r8p->prciop_cscmdbc,
                        d5r8p->prciop_cscmdic,
                        d5r8p->prciop_cscmdsc,
                        d5r8p->prciop_cscmdpi,
                        d5r8p->prciop_cscmdcb,
                        d5r8p->prciop_cscmdsb,
                        d5r8p->prciop_cscmdub,
                        d5r8p->prciop_cscmddb);
                    break;
                case 9:
                    struct d5r9 *d5r9p;
                    d5r9p = (struct d5r9 *) b;
                    //  SQL QUERY R-9
                    sprintf(qbuf, "INSERT INTO d5r9 VALUES ('',FROM_UNIXTIME(%u),'%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s')",
                        utc,
                        d5r9p->prcapc_cryvserv,
                        d5r9p->prcapc_cryrserv,
                        d5r9p->prcapc_crynownq,
                        d5r9p->prcapc_crynovnq,
                        d5r9p->prcapc_crynoxvn,
                        d5r9p->prcapc_crynoxrn,
                        d5r9p->prcapc_crynofnq,
                        d5r9p->prcapc_crynofdq,
                        d5r9p->prcapc_crynovpr,
                        d5r9p->prcapc_crynovpc,
                        d5r9p->prcapc_crynorpr);
                    break;
                case 10:

                    break;
                case 11:
                    struct d5r11 *d5r11p;
                    d5r11p = (struct d5r11 *) b;
                    //  SQL QUERY R-11
                    sprintf(qbuf, "INSERT INTO d5r11 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
                        utc,
                        d5r11p->prcins_pfxcpuad,
                        d5r11p->prcins_plskeyik,
                        d5r11p->prcins_plskeysk,
                        d5r11p->prcins_plsprvsv,
                        d5r11p->prcins_plsprvms,
                        d5r11p->prcins_plsprvlp,
                        d5r11p->prcins_plsprvmn,
                        d5r11p->prcins_plsprvmo,
                        d5r11p->prcins_plsprvgp,
                        d5r11p->prcins_plsprvtc,
                        d5r11p->prcins_plsprvlc,
                        d5r11p->prcins_plsptff,
                        d5r11p->prcins_plssckpf,
                        d5r11p->prcins_plsbiscp,
                        d5r11p->prcins_plsbiste,
                        d5r11p->prcins_plsbispb,
                        d5r11p->prcins_plsbisxe,
                        d5r11p->prcins_plsbisxs,
                        d5r11p->prcins_plsbisas,
                        d5r11p->prcins_plskeyrr,
                        d5r11p->prcins_plsbissi,
                        d5r11p->prcins_plspcvsc,
                        d5r11p->prcins_plsvptnv,
                        d5r11p->prcins_plskeyie,
                        d5r11p->prcins_plskeyre,
                        d5r11p->prcins_plskeyse,
                        d5r11p->prcins_plsbisbt,
                        d5r11p->prcins_plsxpgin,
                        d5r11p->prcins_plsxpgou,
                        d5r11p->prcins_plsviesb,
                        d5r11p->prcins_plsxpg5a,
                        d5r11p->prcins_plsbisst,
                        d5r11p->prcins_plsstfle,
                        d5r11p->prcins_pls0stfl,
                        d5r11p->prcins_plslpswe,
                        d5r11p->prcins_plsbisiu,
                        d5r11p->prcins_pls0epsw,
                        d5r11p->prcins_plsvidte,
                        d5r11p->prcins_pls0esea,
                        d5r11p->prcins_plsessa,
                        d5r11p->prcins_plsprvtp,
                        d5r11p->prcins_plsprvsg,
                        d5r11p->prcins_plsprvlg,
                        d5r11p->prcins_plsprvvn,
                        d5r11p->prcins_plstccc,
                        d5r11p->prcins_plssschc,
                        d5r11p->prcins_plsrschc,
                        d5r11p->prcins_plssioct,
                        d5r11p->prcins_plssiofc,
                        d5r11p->prcins_plsctss,
                        d5r11p->prcins_plsctrs,
                        d5r11p->prcins_plsctcs,
                        d5r11p->prcins_plscths);
                    break;
                case 12:
                    struct d5r12 *d5r12p;
                    d5r12p = (struct d5r12 *) b;
                    //  SQL QUERY R-12
                    sprintf(qbuf, "INSERT INTO d5r12 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
                        utc,
                        d5r12p->prcdia_pfxcpuad,
                        d5r12p->prcdia_plsdgx00,
                        d5r12p->prcdia_plsdgx04,
                        d5r12p->prcdia_plsdgx08,
                        d5r12p->prcdia_plsdgx0c,
                        d5r12p->prcdia_plsdgx10,
                        d5r12p->prcdia_plsdgx14,
                        d5r12p->prcdia_plsdgx18,
                        d5r12p->prcdia_plsdgx1c,
                        d5r12p->prcdia_plsdgx20,
                        d5r12p->prcdia_plsdgx24,
                        d5r12p->prcdia_plsdgx28,
                        d5r12p->prcdia_plsdgx2c,
                        d5r12p->prcdia_plsdgx30,
                        d5r12p->prcdia_plsdgx34,
                        d5r12p->prcdia_plsdgx38,
                        d5r12p->prcdia_plsdgx3c,
                        d5r12p->prcdia_plsdgx40,
                        d5r12p->prcdia_plsdgx44,
                        d5r12p->prcdia_plsdgx48,
                        d5r12p->prcdia_plsdgx4c,
                        d5r12p->prcdia_plsdgx50,
                        d5r12p->prcdia_plsdgx54,
                        d5r12p->prcdia_plsdgx58,
                        d5r12p->prcdia_plsdgx5c,
                        d5r12p->prcdia_plsdgx60,
                        d5r12p->prcdia_plsdgx64,
                        d5r12p->prcdia_plsdgx68,
                        d5r12p->prcdia_plsdgx6c,
                        d5r12p->prcdia_plsdgx70,
                        d5r12p->prcdia_plsdgx74,
                        d5r12p->prcdia_plsdgx78,
                        d5r12p->prcdia_plsdgx7c,
                        d5r12p->prcdia_plsdgx80,
                        d5r12p->prcdia_plsdgx84,
                        d5r12p->prcdia_plsdgx88,
                        d5r12p->prcdia_plsdgx8c,
                        d5r12p->prcdia_plsdgx90,
                        d5r12p->prcdia_plsdgx94,
                        d5r12p->prcdia_plsdgx98,
                        d5r12p->prcdia_plsdgx9c,
                        d5r12p->prcdia_plsdgxa0,
                        d5r12p->prcdia_plsdgxa4,
                        d5r12p->prcdia_plsdgxa8,
                        d5r12p->prcdia_plsdgxac,
                        d5r12p->prcdia_plsdgxb0,
                        d5r12p->prcdia_plsdgxb4,
                        d5r12p->prcdia_plsdgxb8,
                        d5r12p->prcdia_plsdgxbc,
                        d5r12p->prcdia_plsdgxc0,
                        d5r12p->prcdia_plsdgxc4,
                        d5r12p->prcdia_plsdgxc8,
                        d5r12p->prcdia_plsdgxcc,
                        d5r12p->prcdia_plsdgxd0,
                        d5r12p->prcdia_plsdgxd4,
                        d5r12p->prcdia_plsdgxd8,
                        d5r12p->prcdia_plsdgxdc,
                        d5r12p->prcdia_plsdgxe0,
                        d5r12p->prcdia_plsdgxe4,
                        d5r12p->prcdia_plsdgxe8,
                        d5r12p->prcdia_plsdgxec,
                        d5r12p->prcdia_plsdgxf0,
                        d5r12p->prcdia_plsdgxf4,
                        d5r12p->prcdia_plsdgxf8,
                        d5r12p->prcdia_plsdgxfc,
                        d5r12p->prcdia_plsdguct,
                        d5r12p->prcdia_plsdg200,
                        d5r12p->prcdia_plsdg204,
                        d5r12p->prcdia_plsdg208,
                        d5r12p->prcdia_plsdg20c,
                        d5r12p->prcdia_plsdg210,
                        d5r12p->prcdia_plsdg214,
                        d5r12p->prcdia_plsdg218,
                        d5r12p->prcdia_plsdg21c,
                        d5r12p->prcdia_plsdg220,
                        d5r12p->prcdia_plsdg224,
                        d5r12p->prcdia_plsdg228,
                        d5r12p->prcdia_plsdg22c,
                        d5r12p->prcdia_plsdg230,
                        d5r12p->prcdia_plsdg234,
                        d5r12p->prcdia_plsdg238,
                        d5r12p->prcdia_plsdg23c,
                        d5r12p->prcdia_plsdg240,
                        d5r12p->prcdia_plsdg244,
                        d5r12p->prcdia_plsdg248,
                        d5r12p->prcdia_plsdg24c,
                        d5r12p->prcdia_plsdg250,
                        d5r12p->prcdia_plsdg254,
                        d5r12p->prcdia_plsdg258,
                        d5r12p->prcdia_plsdg25c,
                        d5r12p->prcdia_plsdg260,
                        d5r12p->prcdia_plsdg264,
                        d5r12p->prcdia_plsdg268,
                        d5r12p->prcdia_plsdg26c,
                        d5r12p->prcdia_plsdg270,
                        d5r12p->prcdia_plsdg274,
                        d5r12p->prcdia_plsdg278,
                        d5r12p->prcdia_plsdg27c,
                        d5r12p->prcdia_plsdg280,
                        d5r12p->prcdia_plsdg284,
                        d5r12p->prcdia_plsdg288,
                        d5r12p->prcdia_plsdg28c,
                        d5r12p->prcdia_plsdg290,
                        d5r12p->prcdia_plsdg294,
                        d5r12p->prcdia_plsdg298,
                        d5r12p->prcdia_plsdg29c,
                        d5r12p->prcdia_plsdg2a0,
                        d5r12p->prcdia_plsdg2a4,
                        d5r12p->prcdia_plsdg2a8,
                        d5r12p->prcdia_plsdg2ac,
                        d5r12p->prcdia_plsdg2b0,
                        d5r12p->prcdia_plsdg2b4,
                        d5r12p->prcdia_plsdg2b8,
                        d5r12p->prcdia_plsdg2bc,
                        d5r12p->prcdia_plsdg2c0,
                        d5r12p->prcdia_plsdg2c4,
                        d5r12p->prcdia_plsdg2c8,
                        d5r12p->prcdia_plsdg2cc,
                        d5r12p->prcdia_plsdg2d0,
                        d5r12p->prcdia_plsdg2d4,
                        d5r12p->prcdia_plsdg2d8,
                        d5r12p->prcdia_plsdg2dc,
                        d5r12p->prcdia_plsdg2e0,
                        d5r12p->prcdia_plsdg2e4,
                        d5r12p->prcdia_plsdg2e8,
                        d5r12p->prcdia_plsdg2ec,
                        d5r12p->prcdia_plsdg2f0,
                        d5r12p->prcdia_plsdg2f4,
                        d5r12p->prcdia_plsdg2f8,
                        d5r12p->prcdia_plsdg2fc,
                        d5r12p->prcdia_plsdg300,
                        d5r12p->prcdia_plsdg304,
                        d5r12p->prcdia_plsdg308,
                        d5r12p->prcdia_plsdg30c,
                        d5r12p->prcdia_plsdg310,
                        d5r12p->prcdia_plsdg314,
                        d5r12p->prcdia_plsdg318,
                        d5r12p->prcdia_plsdg31c,
                        d5r12p->prcdia_plsdg320,
                        d5r12p->prcdia_plsdg324,
                        d5r12p->prcdia_plsdg328,
                        d5r12p->prcdia_plsdg32c,
                        d5r12p->prcdia_plsdg330,
                        d5r12p->prcdia_plsdg334,
                        d5r12p->prcdia_plsdg338,
                        d5r12p->prcdia_plsdg33c,
                        d5r12p->prcdia_plsdg340,
                        d5r12p->prcdia_plsdg344,
                        d5r12p->prcdia_plsdg348,
                        d5r12p->prcdia_plsdg34c,
                        d5r12p->prcdia_plsdg350,
                        d5r12p->prcdia_plsdg354,
                        d5r12p->prcdia_plsdg358,
                        d5r12p->prcdia_plsdg35c,
                        d5r12p->prcdia_plsdg360,
                        d5r12p->prcdia_plsdg364,
                        d5r12p->prcdia_plsdg368,
                        d5r12p->prcdia_plsdg36c,
                        d5r12p->prcdia_plsdg370,
                        d5r12p->prcdia_plsdg374,
                        d5r12p->prcdia_plsdg378,
                        d5r12p->prcdia_plsdg37c,
                        d5r12p->prcdia_plsdg380,
                        d5r12p->prcdia_plsdg384,
                        d5r12p->prcdia_plsdg388,
                        d5r12p->prcdia_plsdg38c,
                        d5r12p->prcdia_plsdg390,
                        d5r12p->prcdia_plsdg394,
                        d5r12p->prcdia_plsdg398,
                        d5r12p->prcdia_plsdg39c,
                        d5r12p->prcdia_plsdg3a0,
                        d5r12p->prcdia_plsdg3a4,
                        d5r12p->prcdia_plsdg3a8,
                        d5r12p->prcdia_plsdg3ac,
                        d5r12p->prcdia_plsdg3b0,
                        d5r12p->prcdia_plsdg3b4,
                        d5r12p->prcdia_plsdg3b8,
                        d5r12p->prcdia_plsdg3bc,
                        d5r12p->prcdia_plsdg3c0,
                        d5r12p->prcdia_plsdg3c4,
                        d5r12p->prcdia_plsdg3c8,
                        d5r12p->prcdia_plsdg3cc,
                        d5r12p->prcdia_plsdg3d0,
                        d5r12p->prcdia_plsdg3d4,
                        d5r12p->prcdia_plsdg3d8,
                        d5r12p->prcdia_plsdg3dc,
                        d5r12p->prcdia_plsdg3e0,
                        d5r12p->prcdia_plsdg3e4,
                        d5r12p->prcdia_plsdg3e8,
                        d5r12p->prcdia_plsdg3ec,
                        d5r12p->prcdia_plsdg3f0,
                        d5r12p->prcdia_plsdg3f4,
                        d5r12p->prcdia_plsdg3f8,
                        d5r12p->prcdia_plsdg3fc,
                        d5r12p->prcdia_plstotdi);
                    break;
                default:
                    unkn_flag = true;
                    break;
            }
            break;
        case 6:
            switch (r) {
                case 1:
                    struct d6r1 *d6r1p;
                    d6r1p = (struct d6r1 *) b;
                    //EBCDIC 2 ASCII
                    e2a(d6r1p->iodvon_rdevchps, 8);
                    e2a(d6r1p->iodvon_rdcrcuc, 1);
                    e2a(d6r1p->iodvon_rdcobrco, 1);
                    e2a(d6r1p->iodvon_rdevser, 6);
                    e2a(d6r1p->iodvon_edevpth1, 20);
                    e2a(d6r1p->iodvon_edevfcp1, 2);
                    e2a(d6r1p->iodvon_edevwpn1, 8);
                    e2a(d6r1p->iodvon_edevlun1, 8);
                    e2a(d6r1p->iodvon_edevpth2, 20);
                    e2a(d6r1p->iodvon_edevfcp2, 2);
                    e2a(d6r1p->iodvon_edevwpn2, 8);
                    e2a(d6r1p->iodvon_edevlun2, 8);
                    e2a(d6r1p->iodvon_edevpth3, 20);
                    e2a(d6r1p->iodvon_edevfcp3, 2);
                    e2a(d6r1p->iodvon_edevwpn3, 8);
                    e2a(d6r1p->iodvon_edevlun3, 8);
                    e2a(d6r1p->iodvon_edevpth4, 20);
                    e2a(d6r1p->iodvon_edevfcp4, 2);
                    e2a(d6r1p->iodvon_edevwpn4, 8);
                    e2a(d6r1p->iodvon_edevlun4, 8);
                    e2a(d6r1p->iodvon_edevpth5, 20);
                    e2a(d6r1p->iodvon_edevfcp5, 2);
                    e2a(d6r1p->iodvon_edevwpn5, 8);
                    e2a(d6r1p->iodvon_edevlun5, 8);
                    e2a(d6r1p->iodvon_edevpth6, 20);
                    e2a(d6r1p->iodvon_edevfcp6, 2);
                    e2a(d6r1p->iodvon_edevwpn6, 8);
                    e2a(d6r1p->iodvon_edevlun6, 8);
                    e2a(d6r1p->iodvon_edevpth7, 20);
                    e2a(d6r1p->iodvon_edevfcp7, 2);
                    e2a(d6r1p->iodvon_edevwpn7, 8);
                    e2a(d6r1p->iodvon_edevlun7, 8);
                    e2a(d6r1p->iodvon_edevpth8, 20);
                    e2a(d6r1p->iodvon_edevfcp8, 2);
                    e2a(d6r1p->iodvon_edevwpn8, 8);
                    e2a(d6r1p->iodvon_edevlun8, 8);
                    //  SQL QUERY R-1
			        sprintf(qbuf, "INSERT INTO d6r1 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%s','%u','%u','%u','%u,'%u','%s','%u','%u','%u','%u','%s','%s','%s','%s,'%s','%s','%s','%s','%s','%s','%s','%s','%s','%s,'%s','%s','%s','%s','%s','%s','%s','%s','%s','%s,'%s','%s','%s','%s','%s','%s','%s','%s','%u','%u')",
			            utc,
                        d6r1p->iodvon_rdevtype,
                        d6r1p->iodvon_rdevclas,
                        d6r1p->iodvon_rdevdvid,
                        d6r1p->iodvon_calmodln,
                        d6r1p->iodvon_rdevlpm,
                        d6r1p->iodvon_rdevdev,
                        d6r1p->iodvon_rdevsid,
                        d6r1p->iodvon_rdevchps,
                        d6r1p->iodvon_rdevcuid,
                        d6r1p->iodvon_rdevcumn,
                        d6r1p->iodvon_calflags,
                        d6r1p->iodvon_rdcrcuc,
                        d6r1p->iodvon_rdcobrco,
                        d6r1p->iodvon_rdevser,
                        d6r1p->iodvon_calrdevsid,
                        d6r1p->iodvon_calrdevdev,
                        d6r1p->iodvon_rdevpvfg,
                        d6r1p->iodvon_edevtype,
                        d6r1p->iodvon_edevpth1,
                        d6r1p->iodvon_edevfcp1,
                        d6r1p->iodvon_edevwpn1,
                        d6r1p->iodvon_edevlun1,
                        d6r1p->iodvon_edevpth2,
                        d6r1p->iodvon_edevfcp2,
                        d6r1p->iodvon_edevwpn2,
                        d6r1p->iodvon_edevlun2,
                        d6r1p->iodvon_edevpth3,
                        d6r1p->iodvon_edevfcp3,
                        d6r1p->iodvon_edevwpn3,
                        d6r1p->iodvon_edevlun3,
                        d6r1p->iodvon_edevpth4,
                        d6r1p->iodvon_edevfcp4,
                        d6r1p->iodvon_edevwpn4,
                        d6r1p->iodvon_edevlun4,
                        d6r1p->iodvon_edevpth5,
                        d6r1p->iodvon_edevfcp5,
                        d6r1p->iodvon_edevwpn5,
                        d6r1p->iodvon_edevlun5,
                        d6r1p->iodvon_edevpth6,
                        d6r1p->iodvon_edevfcp6,
                        d6r1p->iodvon_edevwpn6,
                        d6r1p->iodvon_edevlun6,
                        d6r1p->iodvon_edevpth7,
                        d6r1p->iodvon_edevfcp7,
                        d6r1p->iodvon_edevwpn7,
                        d6r1p->iodvon_edevlun7,
                        d6r1p->iodvon_edevpth8,
                        d6r1p->iodvon_edevfcp8,
                        d6r1p->iodvon_edevwpn8,
                        d6r1p->iodvon_edevlun8,
                        d6r1p->iodvon_prefpath,
                        d6r1p->iodvon_rdevhppl);
                    break;
                case 2:
                    struct d6r2 *d6r2p;
                    d6r2p = (struct d6r2 *) b;
                    //  SQL QUERY R-2
			        sprintf(qbuf, "INSERT INTO d6r2 VALUES ('',FROM_UNIXTIME(%u),'%u','%u')",		 
                        utc,
                        d6r2p->iodvof_rdevsid,
                        d6r2p->iodvof_rdevdev);
                    break;
                case 3:
                
                    break;
                case 4:
                
                    break;
                case 5:
                    struct d6r5 *d6r5p;
                    d6r5p = (struct d6r5 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d6r5p->iodatd_rdevchps, 8);	//check if it is really in EBCDIC format
                    //  SQL QUERY R-5
			        sprintf(qbuf, "INSERT INTO d6r5 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%s','%u','%u','%u')",		 
			            utc,
                        d6r5p->iodatd_rdevtype,
                        d6r5p->iodatd_rdevclas,
                        d6r5p->iodatd_rdevdvid,
                        d6r5p->iodatd_calmodln,
                        d6r5p->iodatd_rdevlpm,
                        d6r5p->iodatd_rdevdev,
                        d6r5p->iodatd_rdevsid,
                        d6r5p->iodatd_rdevchps,
                        d6r5p->iodatd_rdevcuid,
                        d6r5p->iodatd_rdevcumn,
                        d6r5p->iodatd_calflags);
                    break;
                case 6:
                    struct d6r6 *d6r6p;
                    d6r6p = (struct d6r6 *) b;
                    //  SQL QUERY R-6
                    sprintf(qbuf, "INSERT INTO d6r6 VALUES ('',FROM_UNIXTIME(%u),'%u','%u')",		 
                        utc,
                        d6r6p->ioddtd_rdevsid,
                        d6r6p->ioddtd_rdevdev);
                    break;
                case 7:
                    struct d6r7 *d6r7p;
                    d6r7p = (struct d6r7 *) b;
                    //  SQL QUERY R-7
                    sprintf(qbuf, "INSERT INTO d6r7 VALUES ('',FROM_UNIXTIME(%u),'%u')",		 
                        utc,
                        d6r7p->iodenb_rdevsid);
                    break;
                case 8:
                    struct d6r8 *d6r8p;
                    d6r8p = (struct d6r8 *) b;
                    //  SQL QUERY R-8
			        sprintf(qbuf, "INSERT INTO d6r8 VALUES ('',FROM_UNIXTIME(%u),'%u')",		 
                        utc,
                        d6r8p->ioddsb_rdevsid);
                    break;
                case 9:
                
                    break;
                case 10:
                
                    break;
                case 11:
                
                    break;
                case 12:
                    struct d6r12 *d6r12p;
                    d6r12p = (struct d6r12 *) b;
                    //  SQL QUERY R-12
			        sprintf(qbuf, "INSERT INTO d6r12 VALUES ('',FROM_UNIXTIME(%u),'%u','%u')",		 
                        utc,
                        d6r12p->iodsof_rdevsid,
                        d6r12p->iodsof_rdevdev);
                    break;
                case 13:
                    struct d6r13 *d6r13p;
                    d6r13p = (struct d6r13 *) b;
                    //  SQL QUERY R-13
	        		sprintf(qbuf, "INSERT INTO d6r13 VALUES ('',FROM_UNIXTIME(%u),'%u','%u')",		 
                        utc,
                        d6r13p->iodmon_rdevsid,
                        d6r13p->iodmon_rdevdev);
                    break;
                case 14:
                    struct d6r14 *d6r14p;
                    d6r14p = (struct d6r14 *) b;
                    //  SQL QUERY R-14
	        		sprintf(qbuf, "INSERT INTO d6r14 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",		 
                        utc,
                        d6r14p->iodmof_rdevsid,
                        d6r14p->iodmof_rdevdev,
                        d6r14p->iodmof_scmssch,
                        d6r14p->iodmof_scmcount,
                        d6r14p->iodmof_scmcntim,
                        d6r14p->iodmof_scmfptim,
                        d6r14p->iodmof_scmddtim,
                        d6r14p->iodmof_scmcqtim,
                        d6r14p->iodmof_scmdatim,
                        d6r14p->iodmof_scmdbtim,
                        d6r14p->iodmof_scmirtim,
                        d6r14p->iodmof_scgssch,
                        d6r14p->iodmof_scgcount);
                    break;
                case 15:
                    struct d6r15 *d6r15p;
                    d6r15p = (struct d6r15 *) b;
                    //  SQL QUERY R-15
			        sprintf(qbuf, "INSERT INTO d6r15 VALUES ('',FROM_UNIXTIME(%u),'%u','%u')",		 
                        utc,
                        d6r15p->iodddv_rdevsid,
                        d6r15p->iodddv_rdevdev);
                    break;
                case 16:
                
                    break;
                case 17:
                    struct d6r17 *d6r17p;
                    d6r17p = (struct d6r17 *) b;
                    //  SQL QUERY R-17
			        sprintf(qbuf, "INSERT INTO d6r17 VALUES ('',FROM_UNIXTIME(%u),'%u')",		 
                        utc,
                        d6r17p->ioddch_calchpid);
                    break;
                case 18:
                
                    break;
                case 19:
                
                    break;
                case 20:
                
                    break;
                case 21:
                
                    break;
                case 22:
                    struct d6r22 *d6r22p;
                    d6r22p = (struct d6r22 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d6r22p->iodvsf_lanowner, 8);
                    e2a(d6r22p->iodvsf_lanname, 8);
                    e2a(d6r22p->iodvsf_lanrdd_lancont, 8);
                    e2a(d6r22p->iodvsf_mgswieuser, 8);
                    e2a(d6r22p->iodvsf_swpgroup, 8);
                    //  SQL QUERY R-22
			        sprintf(qbuf, "INSERT INTO d6r22 VALUES ('',FROM_UNIXTIME(%u),'%s','%s','%s','%u','%u','%u','%s','%s','%s','%u','%u','%u')",		 
			            utc,
                        d6r22p->iodvsf_lanowner,
                        d6r22p->iodvsf_lanname,
                        d6r22p->iodvsf_lanrdd_lancont,
                        d6r22p->iodvsf_lanrdd_rdev,
                        d6r22p->iodvsf_lanrdd_osaport,
                        d6r22p->iodvsf_lanmgipa,
                        d6r22p->iodvsf_mgswieuser,
                        d6r22p->iodvsf_mgnicmac,
                        d6r22p->iodvsf_swpgroup,
                        d6r22p->iodvsf_lanrdd_rsn,
                        d6r22p->iodvsf_vqstate,
                        d6r22p->iodvsf_vqsreas);
                    break;
                case 23:
                    struct d6r23 *d6r23p;
                    d6r23p = (struct d6r23 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d6r23p->iodvsr_lanowner, 8);
                    e2a(d6r23p->iodvsr_lanname, 8);
                    e2a(d6r23p->iodvsr_lanrdd_lancont, 8);
                    e2a(d6r23p->iodvsr_mgswieuser, 8);
                    e2a(d6r23p->iodvsr_swpgroup, 8);
                    //  SQL QUERY R-23
			        sprintf(qbuf, "INSERT INTO d6r23 VALUES ('',FROM_UNIXTIME(%u),'%s','%s','%s','%u','%u','%u','%u','%s','%s','%s')",		 
			            utc,
                        d6r23p->iodvsr_lanowner,
                        d6r23p->iodvsr_lanname,
                        d6r23p->iodvsr_lanrdd_lancont,
                        d6r23p->iodvsr_lanrdd_rdev,
                        d6r23p->iodvsr_lanrdd_osaport,
                        d6r23p->iodvsr_swiecapab,
                        d6r23p->iodvsr_lanmgipa,
                        d6r23p->iodvsr_mgswieuser,
                        d6r23p->iodvsr_mgnicmac,
                        d6r23p->iodvsr_swpgroup);
                    break;
                case 24:
                    struct d6r24 *d6r24p;
                    d6r24p = (struct d6r24 *) b;
                    //  SQL QUERY R-24
			        sprintf(qbuf, "INSERT INTO d6r24 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",		 
			            utc,
                        d6r24p->iodszi_rdevdev,
                        d6r24p->iodszi_dskstat,
                        d6r24p->iodszi_dsktime,
                        d6r24p->iodszi_dskxrate,
                        d6r24p->iodszi_dskblksz,
                        d6r24p->iodszi_dskxfers,
                        d6r24p->iodszi_dskblksr,
                        d6r24p->iodszi_dskblksw,
                        d6r24p->iodszi_dskseeko,
                        d6r24p->iodszi_dskqdepth,
                        d6r24p->iodszi_pth1id,
                        d6r24p->iodszi_pth1stat,
                        d6r24p->iodszi_pth1time,
                        d6r24p->iodszi_pth1xrate,
                        d6r24p->iodszi_pth1xfers,
                        d6r24p->iodszi_pth1blksr,
                        d6r24p->iodszi_pth1blksw,
                        d6r24p->iodszi_pth1seeko,
                        d6r24p->iodszi_pth1qdepth,
                        d6r24p->iodszi_pth2id,
                        d6r24p->iodszi_pth2stat,
                        d6r24p->iodszi_pth2time,
                        d6r24p->iodszi_pth2xrate,
                        d6r24p->iodszi_pth2xfers,
                        d6r24p->iodszi_pth2blksr,
                        d6r24p->iodszi_pth2blksw,
                        d6r24p->iodszi_pth2seeko,
                        d6r24p->iodszi_pth2qdepth,
                        d6r24p->iodszi_pth3id,
                        d6r24p->iodszi_pth3stat,
                        d6r24p->iodszi_pth3time,
                        d6r24p->iodszi_pth3xrate,
                        d6r24p->iodszi_pth3xfers,
                        d6r24p->iodszi_pth3blksr,
                        d6r24p->iodszi_pth3blksw,
                        d6r24p->iodszi_pth3seeko,
                        d6r24p->iodszi_pth3qdepth,
                        d6r24p->iodszi_pth4id,
                        d6r24p->iodszi_pth4stat,
                        d6r24p->iodszi_pth4time,
                        d6r24p->iodszi_pth4xrate,
                        d6r24p->iodszi_pth4xfers,
                        d6r24p->iodszi_pth4blksr,
                        d6r24p->iodszi_pth4blksw,
                        d6r24p->iodszi_pth4seeko,
                        d6r24p->iodszi_pth4qdepth,
                        d6r24p->iodszi_pth5id,
                        d6r24p->iodszi_pth5stat,
                        d6r24p->iodszi_pth5time,
                        d6r24p->iodszi_pth5xrate,
                        d6r24p->iodszi_pth5xfers,
                        d6r24p->iodszi_pth5blksr,
                        d6r24p->iodszi_pth5blksw,
                        d6r24p->iodszi_pth5seeko,
                        d6r24p->iodszi_pth5qdepth,
                        d6r24p->iodszi_pth6id,
                        d6r24p->iodszi_pth6stat,
                        d6r24p->iodszi_pth6time,
                        d6r24p->iodszi_pth6xrate,
                        d6r24p->iodszi_pth6xfers,
                        d6r24p->iodszi_pth6blksr,
                        d6r24p->iodszi_pth6blksw,
                        d6r24p->iodszi_pth6seeko,
                        d6r24p->iodszi_pth6qdepth,
                        d6r24p->iodszi_pth7id,
                        d6r24p->iodszi_pth7stat,
                        d6r24p->iodszi_pth7time,
                        d6r24p->iodszi_pth7xrate,
                        d6r24p->iodszi_pth7xfers,
                        d6r24p->iodszi_pth7blksr,
                        d6r24p->iodszi_pth7blksw,
                        d6r24p->iodszi_pth7seeko,
                        d6r24p->iodszi_pth7qdepth,
                        d6r24p->iodszi_pth8id,
                        d6r24p->iodszi_pth8stat,
                        d6r24p->iodszi_pth8time,
                        d6r24p->iodszi_pth8xrate,
                        d6r24p->iodszi_pth8xfers,
                        d6r24p->iodszi_pth8blksr,
                        d6r24p->iodszi_pth8blksw,
                        d6r24p->iodszi_pth8seeko,
                        d6r24p->iodszi_pth8qdepth);
                    break;
                case 25:
                    struct d6r25 *d6r25p;
                    d6r25p = (struct d6r25 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d6r25p->iodqda_vmduser, 8);
                    //  SQL QUERY R-25
			        sprintf(qbuf, "INSERT INTO d6r25 VALUES ('',FROM_UNIXTIME(%u),'%u','%s','%u','%u','%u','%u','%s')",		 
                        utc,
                        d6r25p->iodqda_rdevdev,
                        d6r25p->iodqda_vmduser,
                        d6r25p->iodqda_vdevdev,
                        d6r25p->iodqda_qdiofmt,
                        d6r25p->iodqda_qdinpct,
                        d6r25p->iodqda_qdioutct,
                        d6r25p->iodqda_status);
                    break;
                case 26:
                    struct d6r26 *d6r26p;
                    d6r26p = (struct d6r26 *) b;
                    //  SQL QUERY R-26
			        sprintf(qbuf, "INSERT INTO d6r27 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u''%s','%s','%s','%s','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",
			            utc,
                        d6r26p->iodqds_rdevdev,
                        d6r26p->iodqds_qdiocsgr,
                        d6r26p->iodqds_qdiocsgw,
                        d6r26p->iodqds_qdiocsgs,
                        d6r26p->iodqds_rdevvssr,
                        d6r26p->iodqds_rdevvssw,
                        d6r26p->iodqds_rdevvsss,
                        d6r26p->iodqds_bftoa,
                        d6r26p->iodqds_bytoa,
                        d6r26p->iodqds_bffra,
                        d6r26p->iodqds_byfra,
                        d6r26p->iodqds_rdevvsin,
                        d6r26p->iodqds_rdevvsir,
                        d6r26p->iodqds_rdevvsid,
                        d6r26p->iodqds_qsbsqbvm,
                        d6r26p->iodqds_qsbsqbpv,
                        d6r26p->iodqds_qsbeqbvm,
                        d6r26p->iodqds_qsbeqbpv,
                        d6r26p->iodqds_qsblock,
                        d6r26p->iodqds_qsbfobx,
                        d6r26p->iodqds_qsbolck,
                        d6r26p->iodqds_qsbsigwt,
                        d6r26p->iodqds_qsbsigrt,
                        d6r26p->iodqds_qsbsiglt,
                        d6r26p->iodqds_sumofpin,
                        d6r26p->iodqds_sumunpin);
                    break;
                case 27:
                    struct d6r27 *d6r27p;
                    d6r27p = (struct d6r27 *) b;
                    //  SQL QUERY R-27
			        sprintf(qbuf, "INSERT INTO d6r27 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u''%s','%s','%s','%s','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u')",		 
			            utc,
                        d6r27p->iodqdd_rdevdev,
                        d6r27p->iodqdd_qdiocsgr,
                        d6r27p->iodqdd_qdiocsgw,
                        d6r27p->iodqdd_qdiocsgs,
                        d6r27p->iodqdd_rdevvssr,
                        d6r27p->iodqdd_rdevvssw,
                        d6r27p->iodqdd_rdevvsss,
                        d6r27p->iodqdd_bftoa,
                        d6r27p->iodqdd_bytoa,
                        d6r27p->iodqdd_bffra,
                        d6r27p->iodqdd_byfra,
                        d6r27p->iodqdd_rdevvsin,
                        d6r27p->iodqdd_rdevvsir,
                        d6r27p->iodqdd_rdevvsid,
                        d6r27p->iodqdd_qsbsqbvm,
                        d6r27p->iodqdd_qsbsqbpv,
                        d6r27p->iodqdd_qsbeqbvm,
                        d6r27p->iodqdd_qsbeqbpv,
                        d6r27p->iodqdd_qsblock,
                        d6r27p->iodqdd_qsbfobx,
                        d6r27p->iodqdd_qsbolck,
                        d6r27p->iodqdd_qsbsigwt,
                        d6r27p->iodqdd_qsbsigrt,
                        d6r27p->iodqdd_qsbsiglt,
                        d6r27p->iodqdd_sumofpin,
                        d6r27p->iodqdd_sumunpin);
                    break;
                case 28:
                    struct d6r28 *d6r28p;
                    d6r28p = (struct d6r28 *) b;
                    //  SQL QUERY R-28
	        		sprintf(qbuf, "INSERT INTO d6r28 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%u','%u','%u')",		 
                        utc,
                        d6r28p->iodhpp_hppoolnm,
                        d6r28p->iodhpp_hpptoken,
                        d6r28p->iodhpp_hppnbase,
                        d6r28p->iodhpp_hppnalis,
                        d6r28p->iodhpp_hpptries,
                        d6r28p->iodhpp_hppfails,
                        d6r28p->iodhpp_hppminct,
                        d6r28p->iodhpp_hppmaxct);
                    break;
                case 29:
                    struct d6r29 *d6r29p;
                    d6r29p = (struct d6r29 *) b;
                    //  SQL QUERY R-29
			        sprintf(qbuf, "INSERT INTO d6r29 VALUES ('',FROM_UNIXTIME(%u),'%u','%u')",		 
                        utc,
                        d6r29p->iodhpc_hppoolnm,
                        d6r29p->iodhpc_hpptoken);
                    break;
                case 30:
                    struct d6r30 *d6r30p;
                    d6r30p = (struct d6r30 *) b;
                    //  SQL QUERY R-30
			        sprintf(qbuf, "INSERT INTO d6r30 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u')",		 
                        utc,
                        d6r30p->iodlpt_cuidssid,
                        d6r30p->iodlpt_cuipvopr_old,
                        d6r30p->iodlpt_cuipvopr_new);
                    break;

                default:
                    unkn_flag = true;
                    break:
            }
            break;
        case 7:
            switch (r) {
                case 1:
                    struct d7r1 *d7r1p;
                    d7r1p = (struct d7r1 *) b;
                    //  EBCDIC 2 ASCII
			        e2a(d7r1p->seksek_vmduser,8);
			        e2a(d7r1p->seksek_caluser,8);

                    //  SQL QUERY R-1
                    sprintf(qbuf, "INSERT INTO d7r1 VALUES ('',FROM_UNIXTIME(%u),'%u','%u','%u','%u','%u','%s','%u','%u','%u','%u','%s','%u')",
                        utc,
                        d7r1p->seksek_rdevsid,
                        d7r1p->seksek_calcurcy,
                        d7r1p->seksek_calskcyl,
                        d7r1p->seksek_calskhd,
                        d7r1p->seksek_calflags,
                        d7r1p->seksek_vmduser,
                        d7r1p->seksek_iorposct,
                        d7r1p->seksek_iorpossm,
                        d7r1p->seksek_calecyl,
                        d7r1p->seksek_vdevdev,
                        d7r1p->seksek_caluser,
                        d7r1p->seksek_rdevdev);
                    break;
                default:
                    unkn_flag = true;
                    break;
            }
            break;
        case 8:
        switch (r) {
                case 1:
                    struct d8r1 *d8r1p;
                    d8r1p = (struct d8r1 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d8r1p->vndses_owner,8);
                    e2a(d8r1p->vndses_lanid,8);
                    e2a(d8r1p->vndses_swpgroup,8);
                    //  SQL QUERY R-1
                    sprintf(qbuf, "INSERT INTO d8r1 VALUES ('',FROM_UNIXTIME(%u),'%hu','%s','%hu','%hu','%s','%hhu','%hhu','%s','%hhu','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%hu','%hu','%u','%hu','%u','%hu','%u','%hu','%u','%hu','%u','%hu','%u','%hu','%u','%hu','%u','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s')",
			            utc,
                        d8r1p->vndses_vdevsub,
                        d8r1p->vndses_owner,
                        d8r1p->vndses_vdevdev,
                        d8r1p->vndses_nicbase,
                        d8r1p->vndses_nicmac,

                        d8r1p->vndses_nictranp,
                        d8r1p->vndses_nictype,
                        d8r1p->vndses_lanid,
                        d8r1p->vndses_vswitch,
                        d8r1p->vndses_nic_lockreqs,

                        d8r1p->vndses_landefer,
                        d8r1p->vndses_txdefers,
                        d8r1p->vndses_rxdefers,
                        d8r1p->vndses_sestxbyt,
                        d8r1p->vndses_sesrxbyt,

                        d8r1p->vndses_sestxpkt,
                        d8r1p->vndses_sestxdsc,
                        d8r1p->vndses_sestxerr,
                        d8r1p->vndses_sesrxpkt,
                        d8r1p->vndses_sesrxdsc,

                        d8r1p->vndses_sesrxerr,
                        d8r1p->vndses_sesrxpci,
                        d8r1p->vndses_sestxpci,
                        d8r1p->vndses_swpgroup,
                        d8r1p->vndses_swpintsc,

                        d8r1p->vndses_niddvnum1,
                        d8r1p->vndses_vrtpfrme1,
                        d8r1p->vndses_niddvnum2,
                        d8r1p->vndses_vrtpfrme2,
                        d8r1p->vndses_niddvnum3,

                        d8r1p->vndses_vrtpfrme3,
                        d8r1p->vndses_niddvnum4,
                        d8r1p->vndses_vrtpfrme4,
                        d8r1p->vndses_niddvnum5,
                        d8r1p->vndses_vrtpfrme5,

                        d8r1p->vndses_niddvnum6,
                        d8r1p->vndses_vrtpfrme6,
                        d8r1p->vndses_niddvnum7,
                        d8r1p->vndses_vrtpfrme7,
                        d8r1p->vndses_niddvnum8,

                        d8r1p->vndses_vrtpfrme8,
                        d8r1p->vndses_txreqs,
                        d8r1p->vndses_txreqshi,
                        d8r1p->vndses_txreqslo,
                        d8r1p->vndses_rxreqs,

                        d8r1p->vndses_rxreqshi,
                        d8r1p->vndses_rxreqslo,
                        d8r1p->vndses_stkreqs,
                        d8r1p->vndses_stkreqhi,
                        d8r1p->vndses_stkreqlo,

                        d8r1p->vndses_stkdefers,
                        d8r1p->vndses_stkdefershi,
                        d8r1p->vndses_stkdeferslo);
                    break;
                case 2:
                    struct d8r2 *d8r2p;
                    d8r2p = (struct d8r2 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d8r2p->vndlsu_lanowner,8);
                    e2a(d8r2p->vndlsu_lanname,8);
                    e2a(d8r2p->vndlsu_nicowner,8);
                    //  SQL QUERY R-2
                    sprintf(qbuf, "INSERT INTO d8r2 VALUES ('',FROM_UNIXTIME(%u),'%s','%s','%s','%hu','%u','%u')",
                        utc,
                        d8r2p->vndlsu_lanowner,
                        d8r2p->vndlsu_lanname,
                        d8r2p->vndlsu_nicowner,
                        d8r2p->vndlsu_nicbase,
                        d8r2p->vndlsu_nicmgpor,
                        d8r2p->vndlsu_nicmgifi);
                    break;
                case 3:
                    struct d8r3 *d8r3p;
                    d8r3p = (struct d8r3 *) b;
                    //  EBCDIC 2 ASCII
                    e2a(d8r3p->vndlsd_lanowner,8);
                    e2a(d8r3p->vndlsd_lanname,8);
                    e2a(d8r3p->vndlsd_nicowner,8);
                    //  SQL QUERY R-3
                    sprintf(qbuf, "INSERT INTO d8r3 VALUES ('',FROM_UNIXTIME(%u),'%s','%s','%s','%u','%u','%u')",
                        utc,
                        d8r3p->vndlsd_lanowner,
                        d8r3p->vndlsd_lanname,
                        d8r3p->vndlsd_nicowner,
                        d8r3p->vndlsd_nicbase,
                        d8r3p->vndlsd_nicmgpor,
                        d8r3p->vndlsd_nicmgifi);
                    break;
                default:
                    unkn_flag = true; 
                    break;
            }
            break;

        case 10:
        switch (r) {
                case 1:

                    break;
                case 2:

                    break;
                default:
                    unkn_flag = true; 
                    break;
            }
            break;
        default:
            unkn_flag = true;       
            break;
    }
    if ( !unkn_flag ) {
        if (mysql_query(&mysql, qbuf)) {
            syslog(LOG_ERR, "%s \n", mysql_error(&mysql));
            return -1;
        }
    } else {
        syslog(LOG_NOTICE, "Unknown Domain-(%d) or Record-(%d). Is it z/VM V5.3 ? \n", d, r);
        return 1;
    }
    return 0;
}
