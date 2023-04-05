/* 
*  This file is part of z/VM Performance Monitor Daemon.
*
*  z/VM Performance Monitor Daemon is free software: you can redistribute
*  it and/or modify it under the terms of the GNU General Public License
*  as published by
*  the Free Software Foundation, either version 2 of the License, or
*  (at your option) any later version.
*
*  z/VM Performance Monitor Daemon is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with z/VM Performance Monitor Daemon.
*  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _V53_RECORDS_H
#define	_V53_RECORDS_H

#ifdef	__cplusplus
extern "C" {
#endif

/* format:
DOMAIN-X, where X is a number of domain
	struct dXrY, where X is a domain's nr and Y is a record nr
*/


//typedef __uint64_t __eu64;    

//DOMAIN-0
    struct d0r1
    {
        __u8 filler[20];
        __u16 sytsyp_pfxcpuad;
        __u16 ibm;
        __u32 sytsyp_plsabnct;
        __u32 sytsyp_plsdiagt;
        __u32 sytsyp_plsprvis;
        __u32 sytsyp_plsextnx;
        __u32 sytsyp_plsextnc;
        __u32 sytsyp_plsmchct;
        __u32 sytsyp_plsctss;
        __u32 sytsyp_plsctrs;
        __u32 sytsyp_plsctcs;
        __u32 sytsyp_plscths;
        __u32 sytsyp_plsctsi;
        __u32 sytsyp_plsctui;
        __u32 sytsyp_plspiopr;
        __u32 sytsyp_plspiopw;
        __u32 sytsyp_plspiosr;
        __u32 sytsyp_plspiosw;
        __u32 sytsyp_plsdguct;
        __u32 sytsyp_plsxitct;
        __u32 sytsyp_plspagps;
        __u32 sytsyp_plsstkpe;
        __u32 sytsyp_plstmrce;
        __u32 sytsyp_plsprvsc;
        __u8 sytsyp_pfxcputy;
        __u8 ibm2[3];
    };
    struct d0r2
    {
        __u8 filler[20];
        __u16 sytprp_pfxcpuad;
        __u16 sytprp_plscuhaf;
        __u8 sytprp_pfxprbtm[8];
        __eu64 sytprp_pfxutime;
        __u8 sytprp_pfxtmsys[8];
        __u8 ibm[8];
        __u8 ibm2[8];
        __u32 ibm3;
        __eu64 sytprp_pfxtotwt;
        __u32 sytprp_pfxrunci;
        __u32 sytprp_pfxrunpf;
        __u32 sytprp_pfxruncp;
        __u32 sytprp_calfstph;
        __eu64 sytprp_pfxspint;
        __u32 sytprp_pfxspinc;
        __u8 sytprp_pfxcputy;
        __u8 ibm4[3];
    };
    struct d0r3
    {
        __u8 filler[20];
        __u32 ibm;
        __u32 ibm2;
        __u32 ibm3;
        __u32 ibm4;
        __u32 sytrsg_sysrsvpg;
        __u32 sytrsg_rsacplok;
        __u32 sytrsg_rsanonpg;
        __u32 sytrsg_rsapgabl;
        __u32 sytrsg_rsaavail;
        __u32 sytrsg_rsafrqwt;
        __u32 sytrsg_rsaxtend;
        __u32 ibm5;
        __u32 sytrsg_rsasavfr;
        __u8 ibm6;
        __u8 sytrsg_calflag1; //bitstring
        __u16 sytrsg_hcpstpmb;
        __u32 sytrsg_sys98xa;
        __u32 ibm7;
        __u32 sytrsg_tcmmidsz;
        __u32 sytrsg_tcmmain;
        __u32 sytrsg_tcmmnmin;
        __u32 sytrsg_tcmmnmax;
        __u32 sytrsg_tcmmndl;
        __u32 sytrsg_tcmstlmn;
        __u32 sytrsg_sysscmav;
        __u32 sytrsg_tcmmnblw;
        __u32 sytrsg_tcmmnabv;
        __u32 sytrsg_rsa2gdct;
        __u32 sytrsg_sysscgct;
        __u8 sytrsg_rsalgfrm[8];
        __u32 sytrsg_rsacplkg;
        __u8 sytrsg_rsa2gavl[8];
        __u32 sytrsg_rsa2gav1;
        __u32 sytrsg_rsa2gav2;
        __u32 sytrsg_rsafsb2g;
        __u32 sytrsg_rsafsa2g;
        __u32 sytrsg_rsafsyub;
        __u32 sytrsg_rsafsyua;
        __u32 sytrsg_rsasxcpl;
        __u32 sytrsg_rsasxcla;
        __u32 sytrsg_rsarfrst;
        __u8 sytrsg_rsarfrsg[8];
        __u32 sytrsg_rsasxbct;
        __u32 sytrsg_rsasxact;
        __u32 sytrsg_rsaafrdb;
        __u8 sytrsg_rsaafrdw[8];
        __u32 sytrsg_rsaafrib;
        __u8 sytrsg_rsaafriu[8];
        __u8 sytrsg_rsacalct[8];
        __u8 sytrsg_rsasng2g[8];
        __u32 sytrsg_rsasngav;
        __u32 sytrsg_rsaltdb1;
        __u32 sytrsg_rsaltda1;
        __u32 sytrsg_rsaltdd1;
        __u32 sytrsg_rsaltdc1;
        __u32 sytrsg_rsaltdb2;
        __u32 sytrsg_rsaltda2;
        __u32 sytrsg_rsaltdd2;
        __u32 sytrsg_rsaltdc2;
        __u32 sytrsg_rsaltdbe;
        __u32 sytrsg_rsaltdae;
        __u32 sytrsg_rsaltdde;
        __u32 sytrsg_rsaltdce;
        __u32 sytrsg_rsadrmb1;
        __u32 sytrsg_rsadrma1;
        __u32 sytrsg_rsadrmd1;
        __u32 sytrsg_rsadrmc1;
        __u32 sytrsg_rsadrmb2;
        __u32 sytrsg_rsadrma2;
        __u32 sytrsg_rsadrmd2;
        __u32 sytrsg_rsadrmc2;
        __u32 sytrsg_rsadrmbe;
        __u32 sytrsg_rsadrmae;
        __u32 sytrsg_rsadrmde;
        __u32 sytrsg_rsadrmce;
        __u32 sytrsg_rsaelgb1;
        __u32 sytrsg_rsaelga1;
        __u32 sytrsg_rsaelgd1;
        __u32 sytrsg_rsaelgc1;
        __u32 sytrsg_rsaelgb2;
        __u32 sytrsg_rsaelga2;
        __u32 sytrsg_rsaelgd2;
        __u32 sytrsg_rsaelgc2;
        __u32 sytrsg_rsaelgbe;
        __u32 sytrsg_rsaelgae;
        __u32 sytrsg_rsaelgde;
        __u32 sytrsg_rsaelgce;
        __u32 sytrsg_rsadspb1;
        __u32 sytrsg_rsadspa1;
        __u32 sytrsg_rsadspd1;
        __u32 sytrsg_rsadspc1;
        __u32 sytrsg_rsadspb2;
        __u32 sytrsg_rsadspa2;
        __u32 sytrsg_rsadspd2;
        __u32 sytrsg_rsadspc2;
        __u32 sytrsg_rsadspbe;
        __u32 sytrsg_rsadspae;
        __u32 sytrsg_rsadspde;
        __u32 sytrsg_rsadspce;
        __u32 sytrsg_rsashrb1;
        __u32 sytrsg_rsashra1;
        __u32 sytrsg_rsashrd1;
        __u32 sytrsg_rsashrc1;
        __u32 sytrsg_rsashrb2;
        __u32 sytrsg_rsashra2;
        __u32 sytrsg_rsashrd2;
        __u32 sytrsg_rsashrc2;
        __u32 sytrsg_rsashrbe;
        __u32 sytrsg_rsashrae;
        __u32 sytrsg_rsashrde;
        __u32 sytrsg_rsashrce;
        __u32 sytrsg_rsaresac;
        __u32 sytrsg_rsaresbc;
        
    };
    struct d0r4
    {
        __u8 filler[20];
	__u16 sytrsp_pfxcpuad;
        __u16 ibm;
        __u32 sytrsp_plsstlfr;
	__u32 sytrsp_plsprqdf;
        __u32 sytrsp_plsshrrd;
        __u32 sytrsp_plsalemp;
        __u32 sytrsp_plsnocmp;
        __u32 sytrsp_plsmvb2g;
        __u32 sytrsp_plsalemg;
        __u32 sytrsp_plsgclem;
        __u32 sytrsp_plsmvabv;
        __u8 sytrsp_pfxcputy;
        __u8 ibm2[3];
        __u32 sytrsp_plsalecl;
        __u32 sytrsp_plsalecg;
    };
    struct d0r5
    {
        __u8 filler[20];
        __u16 sytxsp_pfxcpuad;
        __u16 ibm;
        __u32 sytxsp_pfxpgin;
        __u32 sytxsp_plspgin;
        __u32 sytxsp_plspgout;
        __u32 sytxsp_plspgxrd;
        __u32 sytxsp_plspgxwt;
        __u32 sytxsp_plspgmrx;
        __u32 sytxsp_plspgmrd;
        __u8 sytxsp_pfxcputy;
        __u8 ibm2[3];
    };
    struct d0r6
    {
        __u8 filler[20];
        __u32 sytasg_cal90ful;
        __u32 sytasg_cal91ful;
        __u32 sytasg_calslta1;
        __u32 sytasg_calslti1;
        __u32 ibm;
        __u32 ibm2;
        __u32 sytasg_calslta2;
        __u32 sytasg_calslti2;
        __u32 sytasg_syssfcrt;
        __u32 sytasg_syssfpur;
        __u32 sytasg_caltotm1;
        __u32 sytasg_calavgm1;
        __u32 sytasg_caltotm2;
        __u32 sytasg_calavgm2;
        __u32 sytasg_caldmpav;
        __u32 sytasg_caldmpiu;
    };
    struct d0r7
    {
        __u8 filler[20];
        __u32 sytshs_systanss;
        __u32 sytshs_systadcs;
        __u32 sytshs_rsashare;
        __u32 sytshs_calnumsa;
        __u32 sytshs_rsactshr;
        __u32 sytshs_vmdsforo;
        __u32 sytshs_vmdsfore;
        __u32 sytshs_qdgsyslm;
        __u32 sytshs_qdgusrlm;
        __u32 sytshs_qdgsysca;
        __u32 sytshs_qdglkcnt;
        __u32 sytshs_qdgdisks;
    };
    struct d0r11
    {
        __u8 filler[20];
        __u16 sytcom_pfxcpuad;
        __u16 ibm;
        __u32 sytcom_plsisevm;
        __u32 sytcom_plsisema;
        __u32 sytcom_plsisem;
        __u32 sytcom_plsisera;
        __u32 sytcom_plsisebl;
        __u32 sytcom_plsisemo;
        __u32 sytcom_plsistma;
        __u32 sytcom_plsistvm;
        __u32 sytcom_plsistm;
        __u32 sytcom_plsistra;
        __u32 sytcom_plsistbl;
        __u32 sytcom_plsistmo;
        __u32 sytcom_plsisuvm;
        __u32 sytcom_plsisuma;
        __u32 sytcom_plsisum;
        __u32 sytcom_plsisura;
        __u32 sytcom_plsisubl;
        __u32 sytcom_plsisumo;
        __u32 sytcom_plsvsevm;
        __u32 sytcom_plsvstvm;
        __u32 sytcom_plsvsuvm;
        __u32 sytcom_plsisecc;
        __u32 sytcom_plsistcc;
        __u32 sytcom_plsisucc;
        __u32 sytcom_plsisesi;
        __u32 sytcom_plsistsi;
        __u32 sytcom_plsisusi;
        __u32 sytcom_plsisesp;
        __u32 sytcom_plsistsp;
        __u32 sytcom_plsisusp;
        __u32 sytcom_plsisesy;
        __u32 sytcom_plsistsy;
        __u32 sytcom_plsisusy;
        __u32 sytcom_plsiseac;
        __u32 sytcom_plsistac;
        __u32 sytcom_plsisuac;
        __u32 sytcom_plsiselo;
        __u32 sytcom_plsistlo;
        __u32 sytcom_plsisulo;
        __u32 sytcom_plsisecr;
        __u32 sytcom_plsistcr;
        __u32 sytcom_plsisucr;
        __u32 sytcom_plsiseid;
        __u32 sytcom_plsistid;
        __u32 sytcom_plsisuid;
        __u32 sytcom_plsisecf;
        __u32 sytcom_plsistcf;
        __u32 sytcom_plsisucf;
        __u32 sytcom_plsiucvt;
        __u8 sytcom_pfxcputy;
        __u8 ibm2[3];
        __u32 sytcom_plsisevs;
        __u32 sytcom_plsistvs;
        __u32 sytcom_plsisuvs;
        __u32 sytcom_plsiseas;
        __u32 sytcom_plsistas;
        __u32 sytcom_plsisuas;
        __u32 sytcom_plsisesc;
        __u32 sytcom_plsistsc;
        __u32 sytcom_plsisusc;
        __u32 sytcom_plsiseve;
        __u32 sytcom_plsistve;
        __u32 sytcom_plsisuve;
    };
    struct d0r12
    {
        __u8 filler[20];
        __u32 sytuwt_caltidl;
        __u32 sytuwt_caltsvm;
        __s32 sytuwt_caliowt;
        __s32 sytuwt_calwtpag;
        __s32 sytuwt_calcfwt;
        __s32 sytuwt_calsimwt;
        __s32 sytuwt_calcpuwt;
        __s32 sytuwt_calcpurn;
        __s32 sytuwt_calothr;
        __s32 sytuwt_calqdisp;
        __s32 sytuwt_calelsvm;
        __u16 sytuwt_srmcelig;
        __u16 ibm;
        __s32 sytuwt_srmdsvmw;
        __u32 sytuwt_calioact;
        __u32 sytuwt_calllist;
        __u32 sytuwt_calllcp;
        __u32 sytuwt_calllzap;
        __u32 sytuwt_calllifl;
        __u32 sytuwt_calllzip;
        __s32 sytuwt_calcfcp;
        __s32 sytuwt_calcfzap;
        __s32 sytuwt_calcfifl;
        __s32 sytuwt_calcfzip;
        __s32 sytuwt_calswcp;
        __s32 sytuwt_calswzap;
        __s32 sytuwt_calswifl;
        __s32 sytuwt_calswzip;
        __s32 sytuwt_calcwcp;
        __s32 sytuwt_calcwzap;
        __s32 sytuwt_calcwifl;
        __s32 sytuwt_calcwzip;
        __s32 sytuwt_calcrcp;
        __s32 sytuwt_calcrzap;
        __s32 sytuwt_calcrifl;
        __s32 sytuwt_calcrzip;
    };
    struct d0r13
    {
        __u8 filler[20];
        __u16 sytscp_pfxcpuad;
        __u16 sytscp_plseqkad;
        __u16 sytscp_plsefrc1;
        __u16 sytscp_plsefrc2;
        __u16 sytscp_plsefrc3;
        __u16 ibm;
        __u32 sytscp_plsdspcn;
        __u8 sytscp_pfxcputy;
        __u8 ibm2[3];
        
    };
    struct d0r14
    {
        __u8 filler[20];
        __u32 sytxsg_xstxbget;
        __u32 sytxsg_xstxbrel;
        __u32 sytxsg_xstusrsh;
        __u8 sytxsg_xstctxav[8]; //bitstring
        __u8 sytxsg_xstcppar[8]; //bitstring
        __u32 sytxsg_hcpmdcpy;
        __u32 sytxsg_hcpmdcpn;
        __u32 sytxsg_hcpmdcpr;
        __u32 sytxsg_hcpmdcpw;
        __u32 sytxsg_hcpmdcac;
        __u32 sytxsg_hcpmdcne;
        __u32 ibm;
        __u32 sytxsg_hcpmdcex;
        __u32 sytxsg_hcpmdcli;
        __u32 sytxsg_calmdcau;
        __u32 ibm2;
        __u32 ibm3;
        __u32 ibm4;
        __u32 sytxsg_hcpmdcis;
        __u32 ibm5;
        __u32 ibm6;
        __u32 ibm7;
        __u32 ibm8;
        __u32 ibm9;
        __u32 sytxsg_hcpmdcqc;
        __u32 sytxsg_hcpmdcxg;
        __u32 sytxsg_hcpmdcxr;
        __u32 sytxsg_hcpmdctr;
        __u32 sytxsg_hcpmdcia;
        __u32 sytxsg_hcpmdcib;
        __u32 sytxsg_hcpmdcit;
        __u32 ibm10;
        __u32 sytxsg_tcmxidsz;
        __u32 sytxsg_tcmxsmin;
        __u32 sytxsg_tcmstlxs;
        __u32 sytxsg_xstavgag;
        __u16 sytxsg_hcpstpxb;
        __u8 ibm11[2];
        __u32 sytxsg_tcmfshvm;
        __u32 sytxsg_tcmrdct;
        __u32 sytxsg_tcmpin4k;
    };
    struct d0r15
    {
        __u8 filler[20];
        __u8 sytcug_lcutnpar;
        __u8 sytcug_lcutflag; 
        __u8 ibm[2];
        __u16 sytcug_lcutslce;
        __u16 sytcug_lcutpcct;
        __u16 sytcug_lpnumber;
        __u8 ibm2[1];
        __u8 sytcug_cpuchar; 
        __u16 sytcug_cpucount;
        __u16 sytcug_cpucfgct;
        __u16 sytcug_cpustnby;
        __u16 sytcug_cpuresvd;
        __u8 sytcug_lparname[8];
        __u32 sytcug_lparcaf;
        __u16 sytcug_cpudedct;
        __u16 sytcug_cpushard;
    };
    struct d0r19
    {
        __u8 filler[20];
        __u8 sytsyg_xctmsact[8];	//Accumulated elapsed time (ms)
        __u32 sytsyg_ftrdone;
        __u32 sytsyg_ftrabort;
        __u32 sytsyg_ftrnotel;
        __u32 sytsyg_ftrwrite;
        __u32 sytsyg_ctndone;
        __u32 sytsyg_ctnabort;
        __u32 sytsyg_ctnnotel;
        __u32 sytsyg_scpcapab;
        __u32 sytsyg_cpucapab;
        __u16 sytsyg_cpucount;
        __u16 sytsyg_cpucfgct;
        __u16 sytsyg_cpustnby;
        __u16 sytsyg_cpuresvd;
        __u8 sytsyg_vl3dbct;
        __u8 ibm[1];
        __u16 sytsyg_vl3count;
        __u16 sytsyg_vl3cfgct;
        __u16 sytsyg_vl3stnby;
        __u16 sytsyg_vl3resvd;
        __u8 ibm2[2];
        __u8 sytsyg_vl3mname[8];	//String
        __u32 sytsyg_vl3caf;
        __u8 sytsyg_vl3cpnam[16];	//String
    };
    struct d0r21
    {
        __u8 filler[20];
        __u32 sytsxg_sxssize;
        __u32 sytsxg_rsasxavl;
        __u32 sytsxg_rsasxbka;
        __u32 sytsxg_rsasxbkb;
        __u32 sytsxg_rsasxusd;
        __u32 sytsxg_rsasxucp;
        __u32 sytsxg_rsasxuid;
        __u32 sytsxg_rsasxufs;
        __u32 sytsxg_rsasxufg;
        __u32 sytsxg_rsasxali;
        __u32 sytsxg_rsasxnop;
        __u32 sytsxg_rsasxcla;
        __u32 sytsxg_rsasxqct;
        __u32 sytsxg_rsasxact;
        __u32 sytsxg_rsasxbct;
        __u32 sytsxg_rsarsvsy;
    };
    struct d0r22
    {
        __u8 filler[20];
        __u16 sytsxp_pfxcpuad;
        __u16 ibm;
        __u32 sytsxp_plssxrep;
        __u32 sytsxp_plssxacc;
        __u32 sytsxp_plssxarc;
        __u32 sytsxp_plssxaqc;
        __u32 sytsxp_plsspfsc;
        __u32 sytsxp_plsspgpc;
        __u32 sytsxp_plsspgcc;
        __u32 sytsxp_plsspgct;
        __u32 sytsxp_plssprpc;
        __u32 sytsxp_plssprcc;
        __u32 sytsxp_plssprct;
        __u32 sytsxp_plssprqc;
        __u32 sytsxp_plssprqt;
        __u32 sytsxp_plsspgfc;
        __u32 sytsxp_plssprfc;
        __u8 sytsxp_pfxcputy;
        __u8 ibm2[3];
    };

//DOMAIN-1
    struct d1r1
    {
        __u8 filler[20];
        __u8 mtrepr_edomains;
        __u8 ibm;
        __u16 mtrepr_config;
    };
    struct d1r3
    {
        __u8 filler[20];
        __u32 mtrsus_lostrcct;
    };
    struct d1r4
    {
        __u8 filler[20];
        __u8 mtrsys_hcpcpepp[8]; //bitstring
        __u8 mtrsys_hcpcpeid[8];
        __eu64 mtrsys_systodst; //tod at last ipl
        __eu64 mtrsys_systerm; //tod at termination
        __u8 mtrsys_sysdate[8]; //current date
        __u8 mtrsys_sysabncd[8]; //abend code of last termination
        __u32 ibm;
        __u32 ibm2;
        __u32 ibm3;
        __u32 mtrsys_syszone;
        __u8 mtrsys_calflgs;
        __u8 mtrsys_sysvrfsg;
        __u8 mtrsys_calflg2;
        __u8 ibm4[1];
        __u8 mtrsys_systmid[8];	//sys id
        __u8 mtrsys_sysckvol[6];
        __u8 mtrsys_syswmvol[6];
        __u8 mtrsys_sysmtype[4];  //'0' if not present
        __u8 mtrsys_sysmmodl[16];
        __u8 mtrsys_sysmseqc[16];
        __u8 mtrsys_sysmpom[4];
        __u16 mtrsys_lpnumber;
        __u8 mtrsys_cpuchar;
        __u8 ibm5;
        __u16 mtrsys_cpucount;
        __u16 mtrsys_cpucfgct;
        __u16 mtrsys_cpustnby;
        __u16 mtrsys_cpuresvd;
        __u8 mtrsys_lparname[8];
        __u32 mtrsys_lparcaf;
        __u16 mtrsys_cpudedct;
        __u16 mtrsys_cpushard;
        __u32 mtrsys_cpucapab;
        __u32 mtrsys_scpcapab;
    };
    struct d1r5
    {
        __u8 filler[20];
        __u16 mtrprp_pfxcpuad;
        __u8 mtrprp_pfxidmdl[2];
        __u8 mtrprp_pfxidser[3];
        __u8 ibm;
        __u8 mtrprp_calflags;
        __u8 mtrprp_pcccsu;
        __u8 mtrprp_pfxidver;
        __u8 mtrprp_pfxtype;
        __u8 mtrprp_caluded[8];
        __u8 mtrprp_pfxcputy;
        __u8 ibm2[3];
    };
    struct d1r9
    {
        __u8 filler[20];
        __s32 mtrspr_interval;
        __s32 mtrspr_hfrate;
        __u8 mtrspr_sdomains;
        __u8 ibm;
        __u8 mtrspr_hdomains;
        __u8 ibm2;
        __u16 mtrspr_config;
        __u16 ibm3;
    };
    struct d1r10
    {
        __u8 filler[20];
        __eu64 mtrscm_caltod;
        __u32 mtrscm_calbyct;
    };
    struct d1r17
    {
        __u8 filler[20];
        __u8 mtrxsg_xstotalb[8];
        __u8 mtrxsg_sysxtsiz[8];
    };
    struct d1r18
    {
        __u8 filler[20];
        __u32 mtrccc_cpucapab;
        __u32 mtrccc_scpcapab;
    };
    struct d1r19 		//not tested
    {
     __u8 filler[20];
        __u16 mtrqdc_rdevdev;
        __u8 mtrqdc_vmduser[8];	//String
        __u16 mtrqdc_vdevdev;
        __u16 mtrqdc_qdiofmt;
        __u16 mtrqdc_qdinpct;
        __u16 mtrqdc_qdioutct;
        __u8 mtrqdc_status[4];	//Bitstring
        __u16 ibm;		//?reserved by ibm? -bug in doc
        __u32 mtrqdc_qdiocsgr;
        __u32 mtrqdc_qdiocsgw;
        __u32 mtrqdc_qdiocsgs;
        __u32 mtrqdc_rdevvssr;
        __u32 mtrqdc_rdevvssw;
        __u32 mtrqdc_rdevvsss;
        __u64 mtrqdc_bftoa;
        __u64 mtrqdc_bytoa;
        __u64 mtrqdc_bffra;
        __u64 mtrqdc_byfra;
        __u32 mtrqdc_rdevvsin;
        __u32 mtrqdc_rdevvsir;
        __u32 mtrqdc_rdevvsid;
        __u32 mtrqdc_qsbsqbvm;
        __u32 mtrqdc_qsbsqbpv;
        __u32 mtrqdc_qsbeqbvm;
        __u32 mtrqdc_qsbeqbpv;
        __u32 mtrqdc_qsblock;
        __u32 mtrqdc_qsbfobx;
        __u32 mtrqdc_qsbolck;
        __u32 mtrqdc_qsbsigwt;
        __u32 mtrqdc_qsbsigrt;
        __u32 mtrqdc_qsbsiglt;
        __u32 mtrqdc_sumofpin;
        __u32 mtrqdc_sumunpin;
        __u8 mtrqdc_resvd[208]; //reserved by ibm
    };
    struct d1r20
    {
        __u8 filler[20];
        __u16 mtrhpp_hppoolnm;
        __u16 mtrhpp_hpptoken;
    };

//DOMAIN-2
    struct d2r1
    {
        __u8 filler[20];
        __u8 sclrdb_vmduser[8];
        __u8 sclrdb_calflags;
        __u8 ibm[3];
        __u32 sclrdb_rdevsid;
    };

    struct d2r2
    {
        __u8 filler[20];
        __u8 sclrdc_vmduser[8];
        __u8 sclrdc_calflags;
        __u8 ibm[3];
        __u32 sclrdc_rdevsid;
        __u32 sclrdc_calbyct;
    };
    struct d2r3
    {
        __u8 filler[20];
        __u8 sclwrr_vmduser[8];
        __u8 sclwrr_calflags;
        __u8 ibm[3];
        __u32 sclwrr_rdevsid;
        __u32 sclwrr_calbyct;
    };
    struct d2r4
    {
        __u8 filler[20];
        __u8 scladl_vmduser[8];
        __u32 scladl_srmtotst;
        __u32 scladl_srmwssdl;
        __u16 scladl_srmcdisp;
        __u16 scladl_srmc1dsp;
        __u16 scladl_srmc2dsp;
        __u16 scladl_srmc3dsp;
        __u8 scladl_vmdsvmid[8];
        __u8 scladl_vmdsvmwt;
        __u8 scladl_vmdsvmw2; ///???
        //__u8 scladl_vmdsvmwt;
        __u8 scladl_vmdrdycm;
        //__u8 scladl_vmdsvmwt;
        __u8 scladl_calflag1;
        __u32 scladl_vmdwsspr;
        __u32 scladl_vmdpgrte;
        __u8 scladl_calqstat;
        __u8 scladl_vmdelist;
        __u16 scladl_vmdcpuad;
        __u32 scladl_vmdrplim;
        __u32 scladl_vmdctpvr;
        __u8 scladl_vmdvtime[8];
        __u8 scladl_vmdttime[8];
        __u8 scladl_vmdeprty[8];
        __u8 scladl_vmddprty[8];
        __u8 scladl_vmdoprty[8];
        __u32 scladl_vmdrthru;
        __u32 scladl_vmdctxbk;
        __u32 scladl_vmdflreo;
        __u32 scladl_vmdctorf;
        __u32 scladl_calcppst;
        __u8 scladl_calostat;
        __u8 scladl_calsharf;
        __s16 scladl_vmdslcnt;
        __u8 scladl_vmdeslic[8];
        __u32 scladl_vmdrelsh;
        __u32 scladl_vmdabssh;
        __u32 scladl_vmdvusct;
        __s32 scladl_srmabsdl;
        __s32 scladl_srmreldl;
        __u32 scladl_vmdctcrt;
        __u32 scladl_vmdmxshr;
        __u8 scladl_srmatod[8];
        __u8 scladl_srmatod2[8];
        __u32 scladl_vmdctpvg;
        __u8 scladl_vmdcfgem;
        __u8 scladl_vmdpust;
        __u8 ibm[2];
        __u8 scladl_vmdvtmp[8];
        __u8 scladl_vmdttmp[8];
        __u8 scladl_vmdvtms[8];
        __u8 scladl_vmdttms[8];
    };
    struct d2r5
    {
        __u8 filler[20];
        __u8 sclddl_vmduser[8];
        __u8 sclddl_vmdsvmid[8];
        __u8 sclddl_vmdsvmwt;
        __u8 sclddl_vmdsvmw2;
        //__u8 sclddl_vmdsvmwt;
        __u8 sclddl_vmdrdycm;
        //__u8 sclddl_vmdsvmwt;
        __u8 sclddl_calflag1;
        __u32 sclddl_vmdwsspr;
        __u32 sclddl_vmdpgrte;
        __u32 sclddl_vmdrplim;
        __u32 sclddl_vmdctpvr;
        __u8 sclddl_vmdvtime[8];
        __u8 sclddl_vmdttime[8];
        __u8 sclddl_vmddprty[8];
        __u8 sclddl_vmdoprty[8];
        __u32 sclddl_vmdrthru;
        __u32 sclddl_vmdctxbk;
        __u32 sclddl_vmdflreo;
        __u32 sclddl_vmdctorf;
        __u32 sclddl_calcppst;
        __u8 sclddl_calrstat;
        __u8 sclddl_vmdstate;
        __u8 sclddl_calostat;
        __u8 sclddl_vmdsactl;
        __u32 sclddl_vmdcwss;
        __u8 sclddl_vmdsactx;
        __u8 sclddl_calqstat;
        __u16 sclddl_vmdcpuad;
        __u32 sclddl_vmdctcrt;
        __u32 sclddl_vmdrelsh;
        __u32 sclddl_vmdabssh;
        __u8 sclddl_calsharf;
        __u8 ibm;
        __s16 sclddl_vmdslcnt;
        __u32 sclddl_vmdmxshr;
        __u8 sclddl_srmatod[8];
        __u8 sclddl_srmatod2[8];
        __u32 sclddl_vmdctpvg;
        __u8 sclddl_vmdcfgem;
        __u8 sclddl_vmdpust;
        __u8 ibm2[2];
        __u8 sclddl_vmdvtmp[8];
        __u8 sclddl_vmdttmp[8];
        __u8 sclddl_vmdvtms[8];
        __u8 sclddl_vmdttms[8];
    };
    struct d2r6
    {
        __u8 filler[20];
        __u8 sclael_vmduser[8];
        __u16 sclael_srmc1elg;
        __u16 sclael_srmc2elg;
        __u16 sclael_srmc3elg;
        __u16 sclael_vmdcpuad;
        __u8 sclael_vmdsvmid[8];
        __u8 sclael_vmdsvmwt;
        __u8 sclael_vmdsvmw2;
       // __u8 sclael_vmdsvmwt;
        __u8 sclael_vmdrdycm;
        //__u8 sclael_vmdsvmwt;
        __u8 sclael_calflag1;
        __u32 sclael_vmdwsspr;
        __u32 sclael_vmdpgrte;
        __u8 sclael_calqstat;
        __u8 sclael_vmdelist;
        __u8 sclael_vmdwrkcs;
        __u8 sclael_calostat;
        __u8 sclael_vmdeprty[8];
        __u32 sclael_vmdctpvr;
        __u32 sclael_vmdctxbk;
        __u32 sclael_calcppst;
        __u32 sclael_vmdrelsh;
        __u32 sclael_vmdabssh;
        __s32 sclael_vmdurrsp;
        __s32 sclael_srmabsde;
        __s32 sclael_srmrelde;
        __u32 sclael_vmdctcrt;
        __u8 sclael_calsharf;
        __u8 ibm[3];
        __u32 sclael_vmdmxshr;
        __u8 sclael_srmatod[8];
        __u8 sclael_srmatod2[8];
        __u32 sclael_vmdctpvg;
        __u8 sclael_vmdcfgem;
        __u8 sclael_vmdpust;
        __u8 ibm2[2];
    };
    struct d2r9
    {
        __u8 filler[20];
        __u8 sclshr_vmduser[8];
        __u32 sclshr_vmdrelsh;
        __u32 sclshr_vmdabssh;
        __u8 sclshr_calsharf;
        __u8 ibm[3];
        __u32 sclshr_vmdmxshr;
        __u8 sclshr_vmdcfgem;
        __u8 sclshr_vmdpust;
        __u8 ibm2[2];
    };
     struct d2r10
    {
         __u8 filler[20];
        __u8 sclsqd_vmduser[8];
        __u8 sclsqd_calflag1;
        __u8 ibm[3];
    };
    struct d2r11
    {
        __u8 filler[20];
        __u8 scliop_vmduser[8];
        __u32 scliop_ipqupr1;
        __u8 scliop_newrqlo;
        __u8 scliop_newrqhi;
        __u8 ibm[1];
        __u8 scliop_ipqx0;
        __u32 scliop_sysiopq;
        __u8 scliop_sysiopqh;
        __u8 scliop_sysioplo;
        __u8 scliop_sysiophi;
        __u8 ibm2[1];
    };
    struct d2r12
    {
        __u8 filler[20];
        __u8 sclsca_vmduser[8];
        __u8 sclsca_vmdcfgem;
        __u8 sclsca_vmdpust;
        __u16 ibm;
    };

//DOMAIN-3
    struct d3r1
    {
        __u8 filler[20];
        __u32 storsg_calssubt;
        __u32 ibm;
        __u32 storsg_rsasavfr;
        __u32 storsg_rsamaxpp;
        __u32 storsg_rsacplok;
        __u32 storsg_rsaavllt;
        __u32 storsg_rsaavlht;
        __u32 storsg_xstbprct;
        __u32 storsg_xstsrgct;
        __u32 storsg_xstmrabi;
        __u32 storsg_xstsrabi;
        __u32 storsg_xstsrsct;
        __u32 storsg_calptrrt;
        __u32 storsg_calcaafp;
        __u32 storsg_calascut;
        __u32 storsg_rsasxcpl;
        __u32 storsg_rsasxcla;
        __u32 storsg_rsaavlhg;
        __u32 storsg_rsaavllg;
        __u32 storsg_rsacplkg;
        __u32 storsg_calssubg;
        __u32 storsg_rsarsvsy;
        __u8 storsg_rsacallt[8];
        __u8 storsg_rsacalmt[8];
        __u8 storsg_rsacalut[8];
        __u32 storsg_rsaafsdw;
        __u32 storsg_rsaafsdb;
        __u32 storsg_rsaafsiu;
        __u32 storsg_rsaafsib;
        __u32 storsg_rsavcbdw;
        __u32 storsg_rsavcbdb;
        __u32 storsg_rsavcbiu;
        __u32 storsg_rsavcbib;
        __u32 storsg_rsavfsdw;
        __u32 storsg_rsavfsiu;
        __u32 storsg_rsa2gdct;
        __u32 storsg_rsafrqwt;
        __u32 storsg_rsafrrda;
        __u32 storsg_rsafrrdc;
        __u32 storsg_rsastlwt;
        __u32 storsg_rsaswg2g;
        __u32 storsg_rsafvmud;
        __u32 storsg_rsafvmub;
        __u32 storsg_rsavmxfr;
        __u32 storsg_rsavmxfb;
        __u32 storsg_rsavmxud;
        __u32 storsg_rsavmxub;
        __u32 storsg_rsasysfr;
        __u32 storsg_rsasysfb;
        __u32 storsg_rsasysud;
        __u32 storsg_rsasysub;
        __u32 storsg_rsaplpct;
        __u32 storsg_rsaplpcb;
        __u32 storsg_rsanpgct;
        __u32 storsg_rsanpghi;
        __u32 storsg_rsanolkl;
        __u8 storsg_rsanolka[8];
        __u32 storsg_rsasxnop;
        __u32 storsg_rsapptps;
        __u32 storsg_rsapptpf;
        __u32 storsg_rsapptcs;
        __u32 storsg_rsablkgc;
        __u32 storsg_rsafrqmw;
        __u32 storsg_rsafrqdf;
        __u32 storsg_rsafrqdl;
        __u32 storsg_rsaalfmf;
        __u32 storsg_rsaavclt;
        __u32 storsg_rsaavcht;
        __u32 storsg_rsaavclg;
        __u32 storsg_rsaavchg;
        __u32 storsg_rsaemlo;
        __u32 storsg_rsaemhi;
        __u32 storsg_rsaemcpc;
        __u32 storsg_rsaemerg;
        __u32 storsg_rsaemblo;
        __u32 storsg_rsaempty;
        __u32 storsg_rsaemdfr;
        __u32 storsg_rsaswpwt;
        __u32 storsg_rsaswp2g;
    };
    struct d3r2
    {
        __u8 filler[20];
        __u16 storsp_pfxcpuad;
        __u16 ibm;
        __u32 ibm2;
        __u32 ibm3;
        __u32 ibm4;
        __u32 ibm5;
        __u32 ibm6;
        __u32 ibm7;
        __u32 ibm8;
        __u32 ibm9;
        __u32 storsp_plspread;
        __u32 storsp_plspnew;
        __u32 storsp_pfxclear;
        __u32 storsp_pfxptrct;
        __u32 storsp_plsreles;
        __u32 storsp_plsretfr;
        __u32 storsp_plsrelfr;
        __u32 storsp_plsalnct;
        __u32 storsp_plsstlwt;
        __u32 ibm10;
       // __u8 storsp_fstpass[24];
        __u32 storsp_plsltd1;
        __u32 storsp_plsdorm1;
        __u32 ibm11;
        __u32 storsp_plsshar1;
        __u32 storsp_plselig1;
        __u32 storsp_plsdisp1;
       // __u8 storsp_secpassn[16];
        __u32 storsp_plsltd2;
        __u32 storsp_plsdorm2;
        __u32 storsp_plselig2;
        __u32 storsp_plsdisp2;
       // __u8 storsp_secpasse[20];
        __u32 storsp_plsshare;
        __u32 storsp_plsdorme;
        __u32 storsp_plselige;
        __u32 ibm12;
        __u32 storsp_plsdispe;
        //__u8 storsp_fstpfrm[24];
        __u32 storsp_plsltdp1;
        __u32 storsp_plsdrmp1;
        __u32 storsp_plsshrp1;
        __u32 ibm13;
        __u32 storsp_plsdspp1;
        __u32 storsp_plselgp1;
       // __u8 storsp_secpfrm[20];
        __u32 storsp_plsltdp2;
        __u32 storsp_plsdrmp2;
        __u32 storsp_plsshrp2;
        __u32 storsp_plsdspp2;
        __u32 storsp_plselgp2;
        //__u8 storsp_secpefrm[20];
        __u32 storsp_plsdrmpe;
        __u32 storsp_plsshrpe;
        __u32 ibm14;
        __u32 storsp_plsdsppe;
        __u32 storsp_plselgpe;
        __u32 ibm15;
        __u32 ibm16;
        __u32 ibm17;
        __u32 ibm18;
        __u32 storsp_plspgdrd;
        __u32 storsp_plspgdwt;
        __u32 storsp_plsalncg;
        __u32 storsp_plsretfg;
        __u32 storsp_plsfsprb;
        __u32 storsp_plsfspra;
        __u32 storsp_plsfsctb;
        __u32 storsp_plsfscta;
        __u32 storsp_plsfretb;
        __u32 storsp_plsfreta;
        __u32 storsp_plsfssgb;
        __u32 storsp_plsfssga;
        __u32 storsp_plsfspgb;
        __u32 storsp_plsfspga;
        __u32 storsp_plsbgcnt;
        __u8 storsp_plsfgctm[8];
        __u32 storsp_plsfgcnt;
        __u32 storsp_plsfobem;
        __u32 storsp_plsfssra;
        __u32 storsp_plsfssrb;
        __u32 storsp_plsvatcl;
        __u32 storsp_plsupage;
        __u32 storsp_plsvpage;
        __u32 storsp_plspcpag;
        __u32 storsp_plspupag;
        __u32 storsp_plsuprec;
        __u32 storsp_plsessa;
        __u32 storsp_plsltdpe;
        __u32 storsp_plsasfcl;
        __u32 storsp_plsasfcg;
        __u8 storsp_pfxcputy;
        __u8 ibm19[3];
    };
    struct d3r3
    {
        __u8 filler[20];
        __u8 stoshr_sntname[8];
        __s16 stoshr_sdfidnum;
        __s16 ibm;
        __u32 stoshr_sdfcltim;
        __u16 stoshr_sntusrsh;
        __u16 stoshr_sntusrex;
        __u32 stoshr_ascctprs;
        __u32 stoshr_sntstrct;
        __u32 stoshr_sntndtct;
        __u32 stoshr_asccspst;
        __u32 stoshr_ascptrsh;
        __u8 ibm2[8];
        __u32 stoshr_asccspgr;
        __u32 stoshr_asccspgw;
        __u32 stoshr_asccsxrd;
        __u32 stoshr_asccsxwt;
        __u32 stoshr_asccsmig;
        __u32 ibm3;
        __u32 stoshr_ascctpgs;
        __u32 stoshr_ascctxbk;
        __u32 stoshr_ascctprg;
        __u32 stoshr_aschllc;
        __u32 stoshr_aschlrc;
    };
    struct d3r4
    {
        __u8 filler[20];
        __u8 stoasp_calvser[6];
        __u16 stoasp_rdevdev;
        __u32 stoasp_rdevsid;
        __u32 stoasp_calspool;
        __u32 stoasp_calpage;
        __u32 stoasp_expctsrd;
        __u32 stoasp_expctswr;
        __u32 stoasp_expctprd;
        __u32 stoasp_expctpwr;
        __u32 stoasp_expcurqc;
        __u32 stoasp_expctacp;
        __u32 stoasp_expctusi;
        __u16 stoasp_scmssch;
        __u8 stoasp_calflag1;
        __u8 stoasp_rdevdran;
        __u8 stoasp_expcont[80];
        __u32 stoasp_expdevst;
        __u32 stoasp_expmload;
        __u32 stoasp_cpvlokat;
        __u32 stoasp_cpvalocd;
        __u32 stoasp_scgssch;
    };
    struct d3r5
    {
        __u8 filler[20];
        __u8 stoshs_sdffn[8];
        __u8 stoshs_sdfft[8];
        __u32 stoshs_sdfcltim;
        __s16 stoshs_sdfidnum;
        __u8 stoshs_sdfclass;
        __u8 ibm[1];
    };
    struct d3r6
    {
        __u8 filler[20];
        __u8 stoshp_sdffn[8];
        __u8 stoshp_sdfft[8];
        __u32 stoshp_sdfcltim;
        __s16 stoshp_sdfidnum;
        __u8 stoshp_sdfclass;
        __u8 ibm[1];
    };
    struct d3r7
    {
        __u8 filler[20];
        __u8 stoatc_cpvolser[6];
        __u8 ibm;
        __u8 stoatc_calflags;
        __u8 stoatc_caltype[4];
        __s32 stoatc_calcylno;
        __s32 stoatc_calstart;
        __s32 stoatc_rdcpcyl;
        __u32 stoatc_rdevsid;
        __u16 stoatc_rdevdev;
        __u16 ibm2;
    };
    struct d3r8
    {
        __u8 filler[20];
        __u8 stobpg_pgdbr_tbl[80];
        //__u32 stobpg_pgdbr(1:20);
        __u8 stobpg_pgdbm_tbl[80];
        //__u32 stobpg_pgdbm(1:20);
        __u8 stobpg_pgdbs_tbl[80];
        //__u32 stobpg_pgdbs(1:20);
    };
    struct d3r9
    {
        __u8 filler[20];
        __u32 stoxsg_xstmigs;
        __u32 stoxsg_xstblkdm;
        __u8 stoxsg_xstsumag[8];
        __u32 stoxsg_xstblkcy;
        __u32 stoxsg_xstblksh;
        __u32 stoxsg_xstblksy;
        __u32 stoxsg_xstlothr;
        __u32 stoxsg_xstcycls;
        __u32 stoxsg_xstcpdal;
        __u32 stoxsg_xstguest;
        __u8 stoxsg_xstnoio[8];
    };
    struct d3r10
    {
        __u8 filler[20];
        __u8 stoxsu_vmduser[8];
        __u32 stoxsu_calxstor;
        __u32 stoxsu_calorgin;
        __u32 stoxsu_calxslim;
    };
    struct d3r11
    {
        __u8 filler[20];
        __u8 stoass_cpvolser[6];
        __u8 ibm[2];
        __u32 stoass_rdevsid;
        __u32 stoass_expctsrd;
        __u32 stoass_expctswr;
        __u32 stoass_expctprd;
        __u32 stoass_expctpwr;
        __u32 stoass_expcurqc;
        __u32 stoass_expctacp;
        __u32 stoass_expctusi;
        __u16 stoass_scmssch;
        __u16 ibm2;
        __u32 stoass_scgssch;
        __u16 stoass_rdevdev;
        __u16 ibm3;
    };
    struct d3r12
    {
        __u8 filler[20];
        __u8 stoasc_ascusrid[8];
        __u8 stoasc_ascname[24];
        __s32 stoasc_ascssize;
        __u8 stoasc_ascdefsz[8];
        __u8 stoasc_caldefhi[4];
        __u8 stoasc_caldeflo[4];
    };
    struct d3r13
    {
        __u8 filler[20];
        __u8 stoasd_ascusrid[8];
        __u8 stoasd_ascname[24];
    };
    struct d3r14
    {
        __u8 filler[20];
        __u8 stoasi_ascusrid[8];
        __u8 stoasi_ascname[24];
        __u8 stoasi_calstate;
        __u8 ibm[3];
        __u32 stoasi_ascctspi;
        __u32 stoasi_ascctprs;
        __u32 stoasi_asccspst;
        __u32 stoasi_asccspgr;
        __u32 stoasi_asccspgw;
        __u32 stoasi_asccsxrd;
        __u32 stoasi_asccsxwt;
        __u32 stoasi_asccsmig;
        __u32 stoasi_ascctplk;
        __u32 stoasi_ascctpgs;
        __u32 stoasi_ascctxbk;
        __u32 stoasi_ascssize;
        __u8 stoasi_ascdefsz[8];
        __u8 stoasi_caldefhi[4];
        __u8 stoasi_caldeflo[4];
        __u32 stoasi_ascmvb2g;
        __u32 stoasi_ascctprg;
        __u32 stoasi_aschllc;
        __u32 stoasi_aschlrc;
        __u8 stoasi_ascctplka[8];
    };
    struct d3r15
    {
        __u8 filler[20];
        __u8 stoshl_sdffn[8];
        __u8 stoshl_sdfft[8];
        __u32 stoshl_sdfcltim;
        __s16 stoshl_sdfidnum;
        __u8 stoshl_sdfclass;
        __u8 ibm;
    };
    struct d3r16
    {
        __u8 filler[20];
        __u8 stoshd_sdffn[8];
        __u8 stoshd_sdfft[8];
        __u32 stoshd_sdfcltim;
        __s16 stoshd_sdfidnum;
        __u8 stoshd_sdfclass;
        __u8 ibm;
        __u32 stoshd_ascctprs;
        __u32 stoshd_sntstrct;
        __u32 stoshd_sntndtct;
        __u32 stoshd_asccspst;
        __u32 stoshd_ascptrsh;
        __u8 ibm2[8];
        __u32 stoshd_asccspgr;
        __u32 stoshd_asccspgw;
        __u32 stoshd_asccsxrd;
        __u32 stoshd_asccsxwt;
        __u32 stoshd_asccsmig;
        __u32 ibm3;
        __u32 stoshd_ascctpgs;
        __u32 stoshd_ascctprg;
        __u32 stoshd_aschllc;
        __u32 stoshd_aschlrc;
    };
    struct d3r17
    {
        __u8 filler[20];
        __u8 stovdk_mdiouser[8];
        __u8 stovdk_qdisname[24];
        __u16 stovdk_mdiovdev;
        __u8 stovdk_calflag;
        __u8 ibm[1];
        __u32 stovdk_mdilinks;
        __u32 stovdk_calsize;
        __u32 stovdk_qdiiocnt;
    };
    struct d3r18
    {
        __u8 filler[20];
        __u8 stoscs_poolname[8];
        __u32 stoscs_frxroot;
        __u32 stoscs_frxplen;
        __u32 stoscs_malloc;
        __u32 stoscs_mallocf;
        __u32 stoscs_frees;
        __u32 stoscs_freef;
        __u32 stoscs_current;
        __u32 stoscs_maxalloc;
    };
    struct d3r19
    {
        __u8 filler[20];
        __u32 stosxg_rsasxuot;
        __u32 stosxg_rsasxctg;
        __u32 stosxg_rsasxcpl;
        __u32 stosxg_rsasxpct;
        __u32 stosxg_rsasxdct;
        __u32 stosxg_rsasxdca;
        __u32 stosxg_rsasxdpa;
        __u32 stosxg_rsasxdpb;
        __u32 stosxg_rsasxdfa;
        __u32 stosxg_rsasxdfb;
        __u32 stosxg_rsasxrda;
        __u32 stosxg_rsasxrdc;
        __u32 stosxg_rsasxamx;
        __u32 stosxg_rsasxbmx;
        __u32 stosxg_rsasxqmn;
        __u32 stosxg_rsasxqra;
        __u32 stosxg_rsasxrpm;
    };
    struct d3r20
    {
        __u8 filler[20];
        __u16 stosxp_pfxcpuad;
        __u16 ibm;
        __u32 stosxp_plssutkc;
        __u32 stosxp_plssurtc;
        __u32 stosxp_plssupuc;
        __u32 stosxp_plssuqmt;
        __u32 stosxp_plssatkc;
        __u32 stosxp_plssartc;
        __u32 stosxp_plssapuc;
        __u32 stosxp_plssaqmt;
        __u32 stosxp_plssbtkc;
        __u32 stosxp_plssbrtc;
        __u32 stosxp_plssbpuc;
        __u32 stosxp_plssbqmt;
        __u32 stosxp_plssxals;
        __u32 stosxp_plssxadc;
        __u32 stosxp_plssxasc;
        __u32 stosxp_plsspndp;
        __u32 stosxp_plsspndf;
        __u32 stosxp_plsspgpd;
        __u32 stosxp_plsspgfd;
        __u32 stosxp_plsspgbd;
        __u32 stosxp_plsspdqc;
        __u32 stosxp_plssxipc;
        __u32 stosxp_plssxnst;
        __u32 stosxp_plssxafc;
        __u32 stosxp_plssxcsp;
        __u32 stosxp_plssxald;
        __u8 stosxp_pfxcputy;
        __u8 ibm2[3];
    };

//DOMAIN-4
    struct d4r5
    {
        __u8 filler[20];
        __u8 usedfc_vmduser[8];
        __u16 usedfc_vmdcpuad;
        __u16 ibm;
        __u8 usedfc_vmdputyp;
        __u8 usedfc_vmdcfgem;
        __u8 usedfc_vmdpust;
        __u8 usedfc_oldputyp;
    };
    struct d4r6
    {
        __u8 filler[20];
        __u8 usedtc_vmduser[8];
        __u16 usedtc_vmdcpuad;
        __u8 usedtc_vmdputyp;
        __u8 ibm[1];
    };
    struct d4r7
    {
        __u8 filler[20];
        __u8 userdc_vmduser[8];
        __u16 userdc_vmdcpuad;
        __u16 userdc_newcpuad;
        __u8 userdc_vmdputyp;
        __u8 userdc_newputyp;
        __u8 userdc_vmdcfgem;
        __u8 userdc_vmdpust;
    };
    struct d4r9
    {
        __u8 filler[20];
        __u8 useate_vmduser[8];
        __u16 useate_vmdcpuad;
        __u8 useate_vmdmode;
        __u8 useate_calmode;
        //__u8 useate_vmdttime[8];
        __eu64 useate_vmdttime;
        //__u8 useate_vmdvtime[8];
        __eu64 useate_vmdvtime;
        __u8 ibm[8];
        __u8 ibm2[8];
        __u32 useate_vmdctpvr;
        __u32 useate_vmdctpvl;
        __u32 useate_vmdwsspr;
        __u32 useate_vmdctxbk;
        __u32 useate_vmdctflt;
        __u32 ibm3;
        __u32 useate_vmdctorf;
        __u32 useate_calctpgs;
        __u32 ibm4;
        __u32 useate_vmdctpwt;
        __u32 useate_calcppgr;
        __u32 useate_calcppgw;
        __u32 useate_vmdctspr;
        __u32 useate_vmdctspw;
        __u32 useate_vmdpgspl;
        __u32 useate_vmdvcsct;
        __u32 useate_vmdvdsct;
        __u32 useate_vmdvusct;
        __u32 useate_vmdvtsct;
        __u32 useate_vmdvosct;
        __u32 useate_calcppst;
        __u32 useate_vmdisevm;
        __u32 useate_vmdistvm;
        __u32 useate_vmdisuvm;
        __u32 useate_vmdvsevm;
        __u32 useate_vmdvstvm;
        __u32 useate_vmdvsuvm;
        __u32 useate_vmdx98ct;
        __u32 useate_calcpmig;
        __u32 useate_calcpxwt;
        __u32 useate_calcpxrd;
        __u8 useate_calflag1;
        __u8 useate_vmdstype;
        __u8 useate_calsharf;
        __u8 ibm5;
        __u32 useate_vmdblkct;
        __u32 useate_vmdmdcia;
        __u32 useate_vmdcopct;
        __u32 useate_vmdctiso;
        __u32 useate_vmdrelsh;
        __u32 useate_vmdabssh;
        __u32 useate_vmdssize;
        __u32 useate_vmdmxrvp;
        __u8 useate_vmdactno[8];
        __u8 useate_vmdgrpn[8];
        __u8 useate_caltodon[8];
        __u32 useate_vmdvdisk;
        __u32 useate_vmdmxshr;
        __u8 useate_ascdefsz[8]; //make printf
        __u8 useate_caldefhi[4]; //printf
        __u8 useate_caldeflo[4];
        __u32 useate_vmdctpvg;
        __u32 useate_vmdmvb2g;
        __u32 useate_vebalert;
        __u32 useate_vebtvsct;
        __u32 useate_vebsvsct;
        __u32 useate_vebtpiai;
        __u32 useate_vebvirai;
        __u32 useate_vebhdwai;
        __u8 useate_vmdctpvla[8]; //printf
        __u32 useate_vmdctshl;
        __u8 useate_vmdctshla[8];
        __u8 useate_vmdputyp;
        __u8 useate_vmdcfgem;
        __u8 useate_vmdpust;
        __u8 ibm6;
        //__u8 useate_vmdvtmp[8];
        __eu64 useate_vmdvtmp;
        //__u8 useate_vmdttmp[8];
        __eu64 useate_vmdttmp;
        //__u8 useate_vmdvtms[8];
        __eu64 useate_vmdvtms;
        //__u8 useate_vmdttms[8];
        __eu64 useate_vmdttms;
    };

    struct d4r10
    {
        __u8 filler[20];
        __u8 useite_vmduser[8];
        __u16 useite_vmdcpuad;
        __s16 useite_vmdslcnt;
        __u32 useite_vmdsvmfx;
        __u8 useite_vmdsvmid[8];
        __u8 useite_vmdsvmwt;
        __u8 useite_vmdsvmw2;
        //__u8 useite_vmdsvmwt;
        __u8 useite_vmdrdycm;
        //__u8 useite_vmdsvmwt;
        __u8 useite_calflag1;
        __u32 useite_hfquct;
        __u32 useite_hfdisp0;
        __u32 useite_hfdisp1;
        __u32 useite_hfdisp2;
        __u32 useite_hfdisp3;
        __u32 useite_hfelig0;
        __u32 useite_hfelig1;
        __u32 useite_hfelig2;
        __u32 useite_hfelig3;
        __u32 useite_hfstct;
        __u32 useite_hftidl;
        __u32 useite_hftsvm;
        __u32 useite_hfiowt;
        __u32 useite_hfcfwt;
        __u32 useite_hfsimwt;
        __u32 useite_hfwtpag;
        __u32 useite_hfcpuwt;
        __u32 useite_hfcpurn;
        __u32 useite_hfesvm;
        __u32 useite_hfload;
        __u32 useite_hfdorm;
        __s32 useite_hfdsvm;
        __u32 useite_hfothr;
        __u16 useite_vmdcntid;
        __u16 useite_vmdctidl;
        __u32 useite_vmddfrwk;
        __u8 useite_vmdstate;
        __u8 useite_calostat;
        __u8 useite_calrstat;
        __u8 ibm;
        //__u16 useite_vmdcprmd[4];
        __u16 useite_vmdcprmd_q0;
        __u16 useite_vmdcprmd_q1;
        __u16 useite_vmdcprmd_q2;
        __u16 useite_vmdcprmd_q3;
        //__u16 useite_vmdcwsgd[4];
        __u16 useite_vmdcwsgd_q0;
        __u16 useite_vmdcwsgd_q1;
        __u16 useite_vmdcwsgd_q2;
        __u16 useite_vmdcwsgd_q3;
        //__u16 useite_vmdcetsd[4];
        __u16 useite_vmdcetsd_q0;
        __u16 useite_vmdcetsd_q1;
        __u16 useite_vmdcetsd_q2;
        __u16 useite_vmdcetsd_q3;
        //__u16 useite_vmdcidld[4];
        __u16 useite_vmdcidld_q0;
        __u16 useite_vmdcidld_q1;
        __u16 useite_vmdcidld_q2;
        __u16 useite_vmdcidld_q3;
        __u32 useite_hfioact;
        __u32 useite_hfllist;
        __u32 useite_hfpgact;
        __u8 useite_vmdputyp;
        __u8 useite_vmdcfgem;
        __u8 useite_vmdpust;
        __u8 ibm2;
    };

//DOMAIN-5
    struct d5r1
    {
        __u8 filler[20];
        __u16 prcvon_pfxcpuad;
        __u8 prcvon_pfxidmdl[2];
        __u8 prcvon_pfxidser[3];
        __u8 prcvon_pfxidver;
        __u8 prcvon_pfxcputy;
        __u8 ibm[3];
    };
    struct d5r2
    {
        __u8 filler[20];
        __u16 prcvof_pfxcpuad;
        __u16 ibm;
    };
    struct d5r3
    {
        __u8 filler[20];
        __u16 prcprp_pfxcpuad;
        __u16 ibm[31]; //================
        __u32 prcprp_pfxdspcs;
        __u32 prcprp_plsdspcm;
        __u32 prcprp_dsvmaxus;
       // __u8 prcprp_hfsample[28];
        __u32 prcprp_hfcount;
        __u32 prcprp_hfuserz;
        __u32 prcprp_hfuserc;
        __u8 prcprp_caluded[8];
        __u8 prcprp_pfxtype;
        __u8 ibm2[3];
        __u32 prcprp_hfuserm;
        __u8 prcprp_plsstlct[256];
        __u8 prcprp_pfxcputy;
        __u8 ibm3[3];
    };
    struct d5r6
    {
        __u8 filler[20];
        __u16 prccfn_pfxcpuad;
        __u8 prccfn_pcccsu;
        __u8 ibm[1];
    };
    struct d5r7
    {
        __u8 filler[20];
        __u16 prccff_pfxcpuad;
        __u8 prccff_pcccsu;
        __u8 ibm[1];        
    };
    struct d5r8
    {
        __u8 filler[20];
        __u8 prciop_csciopid;
        //__u8 prciop_csciopvb[8];
        __u8 prciop_cscvblbc;
        __u8 prciop_cscvblic;
        __u8 prciop_cscvblsc;
        __u8 prciop_cscvblpi;
        __u8 prciop_cscvblcb;
        __u8 prciop_cscvblsb;
        __u8 prciop_cscvblub;
        __u8 prciop_cscvbldb;
        __u8 ibm[3];
       // __u8 prciop_csciopmd[64];
        __u8 prciop_cscmdbc[8];
        __u8 prciop_cscmdic[8];
        __u8 prciop_cscmdsc[8];
        __u8 prciop_cscmdpi[8];
        __u8 prciop_cscmdcb[8];
        __u8 prciop_cscmdsb[8];
        __u8 prciop_cscmdub[8];
        __u8 prciop_cscmddb[8];
    };
    struct d5r9
    {
        __u8 filler[20];
        __u8 ibm[4];
        __u8 prcapc_cryvserv[8];
        __u8 prcapc_cryrserv[8];
        __u8 prcapc_crynownq[8];
        __u8 prcapc_crynovnq[8];
        __u8 prcapc_crynoxvn[8];
        __u8 prcapc_crynoxrn[8];
        __u8 prcapc_crynofnq[8];
        __u8 prcapc_crynofdq[8];
        __u8 prcapc_crynovpr[8];
        __u8 prcapc_crynovpc[8];
        __u8 prcapc_crynorpr[8];
    };
    struct d5r11
    {
        __u8 filler[20];
        __u16 prcins_pfxcpuad;
        __u16 ibm;
        __u32 prcins_plskeyik;
        __u32 prcins_plskeysk;
        __u32 prcins_plsprvsv;
        __u32 prcins_plsprvms;
        __u32 prcins_plsprvlp;
        __u32 prcins_plsprvmn;
        __u32 prcins_plsprvmo;
        __u32 prcins_plsprvgp;
        __u32 prcins_plsprvtc;
        __u32 prcins_plsprvlc;
        __u32 prcins_plsptff;
        __u32 prcins_plssckpf;
        __u32 prcins_plsbiscp;
        __u32 prcins_plsbiste;
        __u32 prcins_plsbispb;
        __u32 prcins_plsbisxe;
        __u32 prcins_plsbisxs;
        __u32 prcins_plsbisas;
        __u32 prcins_plskeyrr;
        __u32 prcins_plsbissi;
        __u32 prcins_plspcvsc;
        __u32 prcins_plsvptnv;
        __u32 prcins_plskeyie;
        __u32 prcins_plskeyre;
        __u32 prcins_plskeyse;
        __u32 prcins_plsbisbt;
        __u32 prcins_plsxpgin;
        __u32 prcins_plsxpgou;
        __u32 prcins_plsviesb;
        __u32 prcins_plsxpg5a;
        __u32 prcins_plsbisst;
        __u32 prcins_plsstfle;
        __u32 prcins_pls0stfl;
        __u32 prcins_plslpswe;
        __u32 prcins_plsbisiu;
        __u32 prcins_pls0epsw;
        __u32 prcins_plsvidte;
        __u32 prcins_pls0esea;
        __u32 prcins_plsessa;
        __u32 prcins_plsprvtp;
        __u32 prcins_plsprvsg;
        __u32 prcins_plsprvlg;
        __u32 prcins_plsprvvn;
        __u32 prcins_plstccc;
        __u32 prcins_plssschc;
        __u32 prcins_plsrschc;
        __u32 prcins_plssioct;
        __u32 prcins_plssiofc;
        __u32 prcins_plsctss;
        __u32 prcins_plsctrs;
        __u32 prcins_plsctcs;
        __u32 prcins_plscths;
    };
    struct d5r12
    {
        __u8 filler[20];
        __u16 prcdia_pfxcpuad;
        __u16 ibm;
        __u32 prcdia_plsdgx00;
        __u32 prcdia_plsdgx04;
        __u32 prcdia_plsdgx08;
        __u32 prcdia_plsdgx0c;
        __u32 prcdia_plsdgx10;
        __u32 prcdia_plsdgx14;
        __u32 prcdia_plsdgx18;
        __u32 prcdia_plsdgx1c;
        __u32 prcdia_plsdgx20;
        __u32 prcdia_plsdgx24;
        __u32 prcdia_plsdgx28;
        __u32 prcdia_plsdgx2c;
        __u32 prcdia_plsdgx30;
        __u32 prcdia_plsdgx34;
        __u32 prcdia_plsdgx38;
        __u32 prcdia_plsdgx3c;
        __u32 prcdia_plsdgx40;
        __u32 prcdia_plsdgx44;
        __u32 prcdia_plsdgx48;
        __u32 prcdia_plsdgx4c;
        __u32 prcdia_plsdgx50;
        __u32 prcdia_plsdgx54;
        __u32 prcdia_plsdgx58;
        __u32 prcdia_plsdgx5c;
        __u32 prcdia_plsdgx60;
        __u32 prcdia_plsdgx64;
        __u32 prcdia_plsdgx68;
        __u32 prcdia_plsdgx6c;
        __u32 prcdia_plsdgx70;
        __u32 prcdia_plsdgx74;
        __u32 prcdia_plsdgx78;
        __u32 prcdia_plsdgx7c;
        __u32 prcdia_plsdgx80;
        __u32 prcdia_plsdgx84;
        __u32 prcdia_plsdgx88;
        __u32 prcdia_plsdgx8c;
        __u32 prcdia_plsdgx90;
        __u32 prcdia_plsdgx94;
        __u32 prcdia_plsdgx98;
        __u32 prcdia_plsdgx9c;
        __u32 prcdia_plsdgxa0;
        __u32 prcdia_plsdgxa4;
        __u32 prcdia_plsdgxa8;
        __u32 prcdia_plsdgxac;
        __u32 prcdia_plsdgxb0;
        __u32 prcdia_plsdgxb4;
        __u32 prcdia_plsdgxb8;
        __u32 prcdia_plsdgxbc;
        __u32 prcdia_plsdgxc0;
        __u32 prcdia_plsdgxc4;
        __u32 prcdia_plsdgxc8;
        __u32 prcdia_plsdgxcc;
        __u32 prcdia_plsdgxd0;
        __u32 prcdia_plsdgxd4;
        __u32 prcdia_plsdgxd8;
        __u32 prcdia_plsdgxdc;
        __u32 prcdia_plsdgxe0;
        __u32 prcdia_plsdgxe4;
        __u32 prcdia_plsdgxe8;
        __u32 prcdia_plsdgxec;
        __u32 prcdia_plsdgxf0;
        __u32 prcdia_plsdgxf4;
        __u32 prcdia_plsdgxf8;
        __u32 prcdia_plsdgxfc;
        __u32 prcdia_plsdguct;
        __u32 prcdia_plsdg200;
        __u32 prcdia_plsdg204;
        __u32 prcdia_plsdg208;
        __u32 prcdia_plsdg20c;
        __u32 prcdia_plsdg210;
        __u32 prcdia_plsdg214;
        __u32 prcdia_plsdg218;
        __u32 prcdia_plsdg21c;
        __u32 prcdia_plsdg220;
        __u32 prcdia_plsdg224;
        __u32 prcdia_plsdg228;
        __u32 prcdia_plsdg22c;
        __u32 prcdia_plsdg230;
        __u32 prcdia_plsdg234;
        __u32 prcdia_plsdg238;
        __u32 prcdia_plsdg23c;
        __u32 prcdia_plsdg240;
        __u32 prcdia_plsdg244;
        __u32 prcdia_plsdg248;
        __u32 prcdia_plsdg24c;
        __u32 prcdia_plsdg250;
        __u32 prcdia_plsdg254;
        __u32 prcdia_plsdg258;
        __u32 prcdia_plsdg25c;
        __u32 prcdia_plsdg260;
        __u32 prcdia_plsdg264;
        __u32 prcdia_plsdg268;
        __u32 prcdia_plsdg26c;
        __u32 prcdia_plsdg270;
        __u32 prcdia_plsdg274;
        __u32 prcdia_plsdg278;
        __u32 prcdia_plsdg27c;
        __u32 prcdia_plsdg280;
        __u32 prcdia_plsdg284;
        __u32 prcdia_plsdg288;
        __u32 prcdia_plsdg28c;
        __u32 prcdia_plsdg290;
        __u32 prcdia_plsdg294;
        __u32 prcdia_plsdg298;
        __u32 prcdia_plsdg29c;
        __u32 prcdia_plsdg2a0;
        __u32 prcdia_plsdg2a4;
        __u32 prcdia_plsdg2a8;
        __u32 prcdia_plsdg2ac;
        __u32 prcdia_plsdg2b0;
        __u32 prcdia_plsdg2b4;
        __u32 prcdia_plsdg2b8;
        __u32 prcdia_plsdg2bc;
        __u32 prcdia_plsdg2c0;
        __u32 prcdia_plsdg2c4;
        __u32 prcdia_plsdg2c8;
        __u32 prcdia_plsdg2cc;
        __u32 prcdia_plsdg2d0;
        __u32 prcdia_plsdg2d4;
        __u32 prcdia_plsdg2d8;
        __u32 prcdia_plsdg2dc;
        __u32 prcdia_plsdg2e0;
        __u32 prcdia_plsdg2e4;
        __u32 prcdia_plsdg2e8;
        __u32 prcdia_plsdg2ec;
        __u32 prcdia_plsdg2f0;
        __u32 prcdia_plsdg2f4;
        __u32 prcdia_plsdg2f8;
        __u32 prcdia_plsdg2fc;
        __u32 prcdia_plsdg300;
        __u32 prcdia_plsdg304;
        __u32 prcdia_plsdg308;
        __u32 prcdia_plsdg30c;
        __u32 prcdia_plsdg310;
        __u32 prcdia_plsdg314;
        __u32 prcdia_plsdg318;
        __u32 prcdia_plsdg31c;
        __u32 prcdia_plsdg320;
        __u32 prcdia_plsdg324;
        __u32 prcdia_plsdg328;
        __u32 prcdia_plsdg32c;
        __u32 prcdia_plsdg330;
        __u32 prcdia_plsdg334;
        __u32 prcdia_plsdg338;
        __u32 prcdia_plsdg33c;
        __u32 prcdia_plsdg340;
        __u32 prcdia_plsdg344;
        __u32 prcdia_plsdg348;
        __u32 prcdia_plsdg34c;
        __u32 prcdia_plsdg350;
        __u32 prcdia_plsdg354;
        __u32 prcdia_plsdg358;
        __u32 prcdia_plsdg35c;
        __u32 prcdia_plsdg360;
        __u32 prcdia_plsdg364;
        __u32 prcdia_plsdg368;
        __u32 prcdia_plsdg36c;
        __u32 prcdia_plsdg370;
        __u32 prcdia_plsdg374;
        __u32 prcdia_plsdg378;
        __u32 prcdia_plsdg37c;
        __u32 prcdia_plsdg380;
        __u32 prcdia_plsdg384;
        __u32 prcdia_plsdg388;
        __u32 prcdia_plsdg38c;
        __u32 prcdia_plsdg390;
        __u32 prcdia_plsdg394;
        __u32 prcdia_plsdg398;
        __u32 prcdia_plsdg39c;
        __u32 prcdia_plsdg3a0;
        __u32 prcdia_plsdg3a4;
        __u32 prcdia_plsdg3a8;
        __u32 prcdia_plsdg3ac;
        __u32 prcdia_plsdg3b0;
        __u32 prcdia_plsdg3b4;
        __u32 prcdia_plsdg3b8;
        __u32 prcdia_plsdg3bc;
        __u32 prcdia_plsdg3c0;
        __u32 prcdia_plsdg3c4;
        __u32 prcdia_plsdg3c8;
        __u32 prcdia_plsdg3cc;
        __u32 prcdia_plsdg3d0;
        __u32 prcdia_plsdg3d4;
        __u32 prcdia_plsdg3d8;
        __u32 prcdia_plsdg3dc;
        __u32 prcdia_plsdg3e0;
        __u32 prcdia_plsdg3e4;
        __u32 prcdia_plsdg3e8;
        __u32 prcdia_plsdg3ec;
        __u32 prcdia_plsdg3f0;
        __u32 prcdia_plsdg3f4;
        __u32 prcdia_plsdg3f8;
        __u32 prcdia_plsdg3fc;
        __u32 prcdia_plstotdi;
    };

//DOMAIN-6
    struct d6r1				//not tested
    {
        __u8 filler[20];
        __u8 iodvon_rdevtype;
        __u8 iodvon_rdevclas;
        __u16 iodvon_rdevdvid;
        __u8 iodvon_calmodln;
        __u8 iodvon_rdevlpm;
        __u16 iodvon_rdevdev;
        __u32 iodvon_rdevsid;
        __u8 iodvon_rdevchps[8];	//String
        __u16 iodvon_rdevcuid;
        __u8 iodvon_rdevcumn;
        __u8 iodvon_calflags;
        __u8 iodvon_rdcrcuc;		//Character
        __u8 iodvon_rdcobrco;		//Character
        __u8 iodvon_rdevser[6];		//String
        __u32 iodvon_calrdevsid;
        __u16 iodvon_calrdevdev;
        __u8 iodvon_rdevpvfg;
        __u8 iodvon_edevtype;
        __u8 iodvon_edevpth1[20];	//String
        __u8 ibm[2];
        __u8 iodvon_edevfcp1[2];	//String
        __u8 iodvon_edevwpn1[8];	//String
        __u8 iodvon_edevlun1[8];	//String
        __u8 iodvon_edevpth2[20];	//String
        __u8 ibm2[2];
        __u8 iodvon_edevfcp2[2];	//String
        __u8 iodvon_edevwpn2[8];	//String
        __u8 iodvon_edevlun2[8];	//String
        __u8 iodvon_edevpth3[20];	//String
        __u8 ibm3[2];
        __u8 iodvon_edevfcp3[2];	//String
        __u8 iodvon_edevwpn3[8];	//String
        __u8 iodvon_edevlun3[8];	//String
        __u8 iodvon_edevpth4[20];	//String
        __u8 ibm4[2];
        __u8 iodvon_edevfcp4[2];	//String
        __u8 iodvon_edevwpn4[8];	//String
        __u8 iodvon_edevlun4[8];	//String
        __u8 iodvon_edevpth5[20];	//String
        __u8 ibm5[2];
        __u8 iodvon_edevfcp5[2];	//String
        __u8 iodvon_edevwpn5[8];	//String
        __u8 iodvon_edevlun5[8];	//String
        __u8 iodvon_edevpth6[20];	//String
        __u8 ibm6[2];
        __u8 iodvon_edevfcp6[2];	//String
        __u8 iodvon_edevwpn6[8];	//String
        __u8 iodvon_edevlun6[8];	//String
        __u8 iodvon_edevpth7[20];	//String
        __u8 ibm7[2];
        __u8 iodvon_edevfcp7[2];	//String
        __u8 iodvon_edevwpn7[8];	//String
        __u8 iodvon_edevlun7[8];	//String
        __u8 iodvon_edevpth8[20];	//String
        __u8 ibm8[2];
        __u8 iodvon_edevfcp8[2];	//String
        __u8 iodvon_edevwpn8[8];	//String
        __u8 iodvon_edevlun8[8];	//String
        __u8 iodvon_prefpath;
        __u8 ibm9[3];
        __u16 iodvon_rdevhppl;
        __u16 ibm10;
    };
    struct d6r2
    {
        __u8 filler[20];
        __u32 iodvof_rdevsid;
        __u16 iodvof_rdevdev;
        __u16 ibm;
    };

    struct d6r5				//not tested
    {
        __u8 filler[20];
        __u8 iodatd_rdevtype;
        __u8 iodatd_rdevclas;
        __u16 iodatd_rdevdvid;
        __u8 iodatd_calmodln;
        __u8 iodatd_rdevlpm;
        __u16 iodatd_rdevdev;
        __u32 iodatd_rdevsid;
        __u8 iodatd_rdevchps[8];	//String(EBCDIC) or u64(BIN)?
        __u16 iodatd_rdevcuid;
        __u8 iodatd_rdevcumn;
        __u8 iodatd_calflags;
    };
    struct d6r6
    {
        __u8 filler[20];
        __u32 ioddtd_rdevsid;
        __u16 ioddtd_rdevdev;
        __u16 ibm;
    };
    struct d6r7
    {
        __u8 filler[20];
        __u32 iodenb_rdevsid;
    };
    struct d6r8
    {
        __u8 filler[20];
        __u32 ioddsb_rdevsid;
    };

    struct d6r12
    {
        __u8 filler[20];
        __u32 iodsof_rdevsid;
        __u16 iodsof_rdevdev;
        __u16 ibm;
    };
    struct d6r13
    {
        __u8 filler[20];
        __u32 iodmon_rdevsid;
        __u16 iodmon_rdevdev;
        __u16 ibm;
    };

    struct d6r14
    {
        __u8 filler[20];
        __u32 iodmof_rdevsid;
        __u16 iodmof_rdevdev;
        __u16 ibm;
        __u16 iodmof_scmssch;
        __u16 iodmof_scmcount;
        __u32 iodmof_scmcntim;
        __u32 iodmof_scmfptim;
        __u32 iodmof_scmddtim;
        __u32 iodmof_scmcqtim;
        __u32 iodmof_scmdatim;
        __u32 iodmof_scmdbtim;
        __u32 iodmof_scmirtim;
        __u32 iodmof_scgssch;
        __u32 iodmof_scgcount;
    };
    struct d6r15
    {
        __u8 filler[20];
        __u32 iodddv_rdevsid;
        __u16 iodddv_rdevdev;
        __u16 ibm;
    };
    struct d6r17
    {
        __u8 filler[20];
        __u8 ioddch_calchpid;
        __u8 ibm[3];
    };
    struct d6r22
    {
        __u8 filler[20];
        __u8 iodvsf_lanowner[8];
        __u8 iodvsf_lanname[8];
        __u8 iodvsf_lanrdd_lancont[8];
        __u16 iodvsf_lanrdd_rdev;
        __u8 iodvsf_lanrdd_osaport;
        __u8 ibm;
        __u32 iodvsf_lanmgipa;
        __u8 iodvsf_mgswieuser[8];
        __u8 iodvsf_mgnicmac[6];
        __u16 ibm2;
        __u8 iodvsf_swpgroup[8];
        __u8 iodvsf_lanrdd_rsn;
        __u8 iodvsf_vqstate;
        __u16 iodvsf_vqsreas;
    };
    struct d6r23
    {
        __u8 filler[20];
        __u8 iodvsr_lanowner[8];
        __u8 iodvsr_lanname[8];
        __u8 iodvsr_lanrdd_lancont[8];
        __u16 iodvsr_lanrdd_rdev;
        __u8 iodvsr_lanrdd_osaport;
        __u8 ibm;
        __u32 iodvsr_swiecapab;
        __u32 iodvsr_lanmgipa;
        __u8 iodvsr_mgswieuser[8];
        __u8 iodvsr_mgnicmac[6];
        __u8 ibm2[2];
        __u8 iodvsr_swpgroup[8];
    };
    struct d6r24
    {
        __u8 filler[20];
        __u16 iodszi_rdevdev;
        __u16 ibm;
        __u8 iodszi_dskstat;
        __u8 ibm2;
        __u16 ibm3;
        __u32 iodszi_dsktime;
        __u32 iodszi_dskxrate;
        __u32 iodszi_dskblksz;
        __u32 iodszi_dskxfers;
        __u32 iodszi_dskblksr;
        __u32 iodszi_dskblksw;
        __u32 iodszi_dskseeko;
        __u32 iodszi_dskqdepth;
        __u16 iodszi_pth1id;
        __u8 iodszi_pth1stat;
        __u8 ibm4;
        __u32 iodszi_pth1time;
        __u32 iodszi_pth1xrate;
        __u32 iodszi_pth1xfers;
        __u32 iodszi_pth1blksr;
        __u32 iodszi_pth1blksw;
        __u32 iodszi_pth1seeko;
        __u32 iodszi_pth1qdepth;
        __u16 iodszi_pth2id;
        __u8 iodszi_pth2stat;
        __u8 ibm5;
        __u32 iodszi_pth2time;
        __u32 iodszi_pth2xrate;
        __u32 iodszi_pth2xfers;
        __u32 iodszi_pth2blksr;
        __u32 iodszi_pth2blksw;
        __u32 iodszi_pth2seeko;
        __u32 iodszi_pth2qdepth;
        __u16 iodszi_pth3id;
        __u8 iodszi_pth3stat;
        __u8 ibm6;
        __u32 iodszi_pth3time;
        __u32 iodszi_pth3xrate;
        __u32 iodszi_pth3xfers;
        __u32 iodszi_pth3blksr;
        __u32 iodszi_pth3blksw;
        __u32 iodszi_pth3seeko;
        __u32 iodszi_pth3qdepth;
        __u16 iodszi_pth4id;
        __u8 iodszi_pth4stat;
        __u8 ibm7;
        __u32 iodszi_pth4time;
        __u32 iodszi_pth4xrate;
        __u32 iodszi_pth4xfers;
        __u32 iodszi_pth4blksr;
        __u32 iodszi_pth4blksw;
        __u32 iodszi_pth4seeko;
        __u32 iodszi_pth4qdepth;
        __u16 iodszi_pth5id;
        __u8 iodszi_pth5stat;
        __u8 ibm8;
        __u32 iodszi_pth5time;
        __u32 iodszi_pth5xrate;
        __u32 iodszi_pth5xfers;
        __u32 iodszi_pth5blksr;
        __u32 iodszi_pth5blksw;
        __u32 iodszi_pth5seeko;
        __u32 iodszi_pth5qdepth;
        __u16 iodszi_pth6id;
        __u8 iodszi_pth6stat;
        __u8 ibm9;
        __u32 iodszi_pth6time;
        __u32 iodszi_pth6xrate;
        __u32 iodszi_pth6xfers;
        __u32 iodszi_pth6blksr;
        __u32 iodszi_pth6blksw;
        __u32 iodszi_pth6seeko;
        __u32 iodszi_pth6qdepth;
        __u16 iodszi_pth7id;
        __u8 iodszi_pth7stat;
        __u8 ibm10;
        __u32 iodszi_pth7time;
        __u32 iodszi_pth7xrate;
        __u32 iodszi_pth7xfers;
        __u32 iodszi_pth7blksr;
        __u32 iodszi_pth7blksw;
        __u32 iodszi_pth7seeko;
        __u32 iodszi_pth7qdepth;
        __u16 iodszi_pth8id;
        __u8 iodszi_pth8stat;
        __u8 ibm11;
        __u32 iodszi_pth8time;
        __u32 iodszi_pth8xrate;
        __u32 iodszi_pth8xfers;
        __u32 iodszi_pth8blksr;
        __u32 iodszi_pth8blksw;
        __u32 iodszi_pth8seeko;
        __u32 iodszi_pth8qdepth;
    };
    struct d6r25
    {
        __u8 filler[20];
        __u16 iodqda_rdevdev;
        __u8 iodqda_vmduser[8];
        __u16 iodqda_vdevdev;
        __u16 iodqda_qdiofmt;
        __u16 iodqda_qdinpct;
        __u16 iodqda_qdioutct;
        __u8 iodqda_status[4]; // bitstring 4 bytes
    };
    struct d6r26
    {
        __u8 filler[20];
        __u16 iodqds_rdevdev;
        __u16 ibm;
        __u32 iodqds_qdiocsgr;
        __u32 iodqds_qdiocsgw;
        __u32 iodqds_qdiocsgs;
        __u32 iodqds_rdevvssr;
        __u32 iodqds_rdevvssw;
        __u32 iodqds_rdevvsss;
        __u8 iodqds_bftoa[8]; //bitstring
        __u8 iodqds_bytoa[8]; //bitstring
        __u8 iodqds_bffra[8]; //bitstring
        __u8 iodqds_byfra[8]; //bitstring
        __u32 iodqds_rdevvsin;
        __u32 iodqds_rdevvsir;
        __u32 iodqds_rdevvsid;
        __u32 iodqds_qsbsqbvm;
        __u32 iodqds_qsbsqbpv;
        __u32 iodqds_qsbeqbvm;
        __u32 iodqds_qsbeqbpv;
        __u32 iodqds_qsblock;
        __u32 iodqds_qsbfobx;
        __u32 iodqds_qsbolck;
        __u32 iodqds_qsbsigwt;
        __u32 iodqds_qsbsigrt;
        __u32 iodqds_qsbsiglt;
        __u32 iodqds_sumofpin;
        __u32 iodqds_sumunpin;
        __u8 iodqds_resvd[208];
    };
    struct d6r27
    {
        __u8 filler[20];
        __u16 iodqdd_rdevdev;
        __u16 ibm;
        __u32 iodqdd_qdiocsgr;
        __u32 iodqdd_qdiocsgw;
        __u32 iodqdd_qdiocsgs;
        __u32 iodqdd_rdevvssr;
        __u32 iodqdd_rdevvssw;
        __u32 iodqdd_rdevvsss;
        __u8 iodqdd_bftoa[8]; //bitstring
        __u8 iodqdd_bytoa[8]; //bitstring
        __u8 iodqdd_bffra[8]; //bitstring
        __u8 iodqdd_byfra[8]; //bitstring
        __u32 iodqdd_rdevvsin;
        __u32 iodqdd_rdevvsir;
        __u32 iodqdd_rdevvsid;
        __u32 iodqdd_qsbsqbvm;
        __u32 iodqdd_qsbsqbpv;
        __u32 iodqdd_qsbeqbvm;
        __u32 iodqdd_qsbeqbpv;
        __u32 iodqdd_qsblock;
        __u32 iodqdd_qsbfobx;
        __u32 iodqdd_qsbolck;
        __u32 iodqdd_qsbsigwt;
        __u32 iodqdd_qsbsigrt;
        __u32 iodqdd_qsbsiglt;
        __u32 iodqdd_sumofpin;
        __u32 iodqdd_sumunpin;
        __u8 iodqdd_resvd[208];
    };
    struct d6r28
    {
        __u8 filler[20];
        __u16 iodhpp_hppoolnm;
        __u16 iodhpp_hpptoken;
        __u32 iodhpp_hppnbase;
        __u32 iodhpp_hppnalis;
        __u32 iodhpp_hpptries;
        __u32 iodhpp_hppfails;
        __u32 iodhpp_hppminct;
        __u32 iodhpp_hppmaxct;
    };
    struct d6r29
    {
        __u8 filler[20];
        __u16 iodhpc_hppoolnm;
        __u16 iodhpc_hpptoken;
        __u8 ibm[4];
    };
    struct d6r30
    {
        __u8 filler[20];
        __u16 iodlpt_cuidssid;
        __u8 iodlpt_cuipvopr_old;
        __u8 iodlpt_cuipvopr_new;
        __u8 ibm[4];
    };

//DOMAIN-7
    struct d7r1
    {
        __u8 filler[20];
        __u32 seksek_rdevsid;
        __u16 seksek_calcurcy;
        __u16 seksek_calskcyl;
        __u16 seksek_calskhd;
        __u8 seksek_calflags; //bitstring
        __u8 ibm; //reserved bitstring
        __u8 seksek_vmduser[8];
        __u32 seksek_iorposct;
        __u32 seksek_iorpossm;
        __u16 seksek_calecyl;
        __u16 seksek_vdevdev;
        __u8 seksek_caluser[8];
        __u16 seksek_rdevdev;
        __u16 ibm2;
    };

//DOMAIN-8
    struct d8r1				//not tested, check & rewrite
    {
        __u8 filler[20];
        __u16 vndses_vdevsub;
        __u16 ibm;
        __u8 vndses_owner[8];
        __u16 vndses_vdevdev;
        __u16 vndses_nicbase;
        __u8 vndses_nicmac[6];
        __u8 vndses_nictranp;
        __u8 vndses_nictype;
        __u8 vndses_lanid[16];
        __u8 vndses_vswitch;
        __u8 ibm2[3];
        __u8 vndses_nic_lockreqs[8];
        __u8 vndses_landefer[8];
        __u8 vndses_txdefers[8];
        __u8 vndses_rxdefers[8];
        __u8 vndses_sestxbyt[8];
        __u8 vndses_sesrxbyt[8];
        __u8 vndses_sestxpkt[8];
        __u8 vndses_sestxdsc[8];
        __u8 vndses_sestxerr[8];
        __u8 vndses_sesrxpkt[8];
        __u8 vndses_sesrxdsc[8];
        __u8 vndses_sesrxerr[8];
        __u8 vndses_sesrxpci[8];
        __u8 vndses_sestxpci[8];
        __u8 vndses_swpgroup[8];
        __u16 vndses_swpintsc;
        __u8 ibm3[2];
//start of array port info (8)
        __u16 vndses_niddvnum1;
        __u8 ibm4[2];
        __u32 vndses_vrtpfrme1;

        __u16 vndses_niddvnum2;
        __u8 ibm5[2];
        __u32 vndses_vrtpfrme2;

        __u16 vndses_niddvnum3;
        __u8 ibm6[2];
        __u32 vndses_vrtpfrme3;

        __u16 vndses_niddvnum4;
        __u8 ibm7[2];
        __u32 vndses_vrtpfrme4;

        __u16 vndses_niddvnum5;
        __u8 ibm8[2];
        __u32 vndses_vrtpfrme5;

        __u16 vndses_niddvnum6;
        __u8 ibm9[2];
        __u32 vndses_vrtpfrme6;

        __u16 vndses_niddvnum7;
        __u8 ibm10[2];
        __u32 vndses_vrtpfrme7;

        __u16 vndses_niddvnum8;
        __u8 ibm11[2];
        __u32 vndses_vrtpfrme8;
//end of array of port info
        __u8 vndses_txreqs[8];
        __u8 vndses_txreqshi[4];
        __u8 vndses_txreqslo[4];
        __u8 vndses_rxreqs[8];
        __u8 vndses_rxreqshi[4];
        __u8 vndses_rxreqslo[4];
        __u8 vndses_stkreqs[8];
        __u8 vndses_stkreqhi[4];
        __u8 vndses_stkreqlo[4];
        __u8 vndses_stkdefers[8];
        __u8 vndses_stkdefershi[4];
        __u8 vndses_stkdeferslo[4];
    };
    struct d8r2
    {
        __u8 filler[20];
        __u8 vndlsu_lanowner[8];
        __u8 vndlsu_lanname[8];
        __u8 vndlsu_nicowner[8];
        __u16 vndlsu_nicbase;
        __u16 ibm;
        __u32 vndlsu_nicmgpor;
        __u32 vndlsu_nicmgifi;
    };
    struct d8r3
    {
        __u8 filler[20];
        __u8 vndlsd_lanowner[8];
        __u8 vndlsd_lanname[8];
        __u8 vndlsd_nicowner[8];
        __u16 vndlsd_nicbase;
        __u16 ibm;
        __u32 vndlsd_nicmgpor;
        __u32 vndlsd_nicmgifi;
    };

#ifdef	__cplusplus
}
#endif

#endif	/* _V53_RECORDS_H */
