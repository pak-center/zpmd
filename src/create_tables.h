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


#ifndef _CREATE_TABLES_H
#define	_CREATE_TABLES_H

#ifdef	__cplusplus
extern "C" {
#endif

int create_tables(*mysql);
//MYSQL TABLE DEFINITION BEGIN

//DOMAIN-0's TABLE
const char *query_create_d0r1 =
 "CREATE TABLE IF NOT EXISTS d0r1 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sytsyp_pfxcpuad SMALLINT(1) UNSIGNED, \
 sytsyp_plsabnct INT(1) UNSIGNED, \
 sytsyp_plsdiagt INT(1) UNSIGNED, \
 sytsyp_plsprvis INT(1) UNSIGNED, \
 sytsyp_plsextnx INT(1) UNSIGNED, \
 sytsyp_plsextnc INT(1) UNSIGNED, \
 sytsyp_plsmchct INT(1) UNSIGNED, \
 sytsyp_plsctss INT(1) UNSIGNED, \
 sytsyp_plsctrs INT(1) UNSIGNED, \
 sytsyp_plsctcs INT(1) UNSIGNED, \
 sytsyp_plscths INT(1) UNSIGNED, \
 sytsyp_plsctsi INT(1) UNSIGNED, \
 sytsyp_plsctui INT(1) UNSIGNED, \
 sytsyp_plspiopr INT(1) UNSIGNED, \
 sytsyp_plspiopw INT(1) UNSIGNED, \
 sytsyp_plspiosr INT(1) UNSIGNED, \
 sytsyp_plspiosw INT(1) UNSIGNED, \
 sytsyp_plsdguct INT(1) UNSIGNED, \
 sytsyp_plsxitct INT(1) UNSIGNED, \
 sytsyp_plspagps INT(1) UNSIGNED, \
 sytsyp_plsstkpe INT(1) UNSIGNED, \
 sytsyp_plstmrce INT(1) UNSIGNED, \
 sytsyp_plsprvsc INT(1) UNSIGNED, \
 sytsyp_pfxcputy TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

//d0r2 check and correct time values for total cpu time
const char *query_create_d0r2 =
 "CREATE TABLE IF NOT EXISTS d0r2 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sytprp_pfxcpuad SMALLINT(1) UNSIGNED, \
 sytprp_plscuhaf SMALLINT(1) UNSIGNED, \
 sytprp_pfxprbtm CHAR(8), \
 sytprp_pfxutime BIGINT(1) UNSIGNED, \
 sytprp_pfxtmsys CHAR(8), \
 sytprp_pfxtotwt BIGINT(1) UNSIGNED, \
 sytprp_pfxrunci INT(1) UNSIGNED, \
 sytprp_pfxrunpf INT(1) UNSIGNED, \
 sytprp_pfxruncp INT(1) UNSIGNED, \
 sytprp_calfstph INT(1) UNSIGNED, \
 sytprp_pfxspint BIGINT(1) UNSIGNED, \
 sytprp_pfxspinc INT(1) UNSIGNED, \
 sytprp_pfxcputy TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d0r3 =
 "CREATE TABLE IF NOT EXISTS d0r3 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sytrsg_sysrsvpg INT(1) UNSIGNED, \
 sytrsg_rsacplok INT(1) UNSIGNED, \
 sytrsg_rsanonpg INT(1) UNSIGNED, \
 sytrsg_rsapgabl INT(1) UNSIGNED, \
 sytrsg_rsaavail INT(1) UNSIGNED, \
 sytrsg_rsafrqwt INT(1) UNSIGNED, \
 sytrsg_rsaxtend INT(1) UNSIGNED, \
 sytrsg_rsasavfr INT(1) UNSIGNED, \
 sytrsg_calflag1 TINYINT(1) UNSIGNED, \
 sytrsg_hcpstpmb SMALLINT(1) UNSIGNED, \
 sytrsg_sys98xa INT(1) UNSIGNED, \
 sytrsg_tcmmidsz INT(1) UNSIGNED, \
 sytrsg_tcmmain INT(1) UNSIGNED, \
 sytrsg_tcmmnmin INT(1) UNSIGNED, \
 sytrsg_tcmmnmax INT(1) UNSIGNED, \
 sytrsg_tcmmndl INT(1) UNSIGNED, \
 sytrsg_tcmstlmn INT(1) UNSIGNED, \
 sytrsg_sysscmav INT(1) UNSIGNED, \
 sytrsg_tcmmnblw INT(1) UNSIGNED, \
 sytrsg_tcmmnabv INT(1) UNSIGNED, \
 sytrsg_rsa2gdct INT(1) UNSIGNED, \
 sytrsg_sysscgct INT(1) UNSIGNED, \
 sytrsg_rsalgfrm BINARY(8), \
 sytrsg_rsacplkg INT(1) UNSIGNED, \
 sytrsg_rsa2gavl BINARY(8), \
 sytrsg_rsa2gav1 INT(1) UNSIGNED, \
 sytrsg_rsa2gav2 INT(1) UNSIGNED, \
 sytrsg_rsafsb2g INT(1) UNSIGNED, \
 sytrsg_rsafsa2g INT(1) UNSIGNED, \
 sytrsg_rsafsyub INT(1) UNSIGNED, \
 sytrsg_rsafsyua INT(1) UNSIGNED, \
 sytrsg_rsasxcpl INT(1) UNSIGNED, \
 sytrsg_rsasxcla INT(1) UNSIGNED, \
 sytrsg_rsarfrst INT(1) UNSIGNED, \
 sytrsg_rsarfrsg BINARY(8), \
 sytrsg_rsasxbct INT(1) UNSIGNED, \
 sytrsg_rsasxact INT(1) UNSIGNED, \
 sytrsg_rsaafrdb INT(1) UNSIGNED, \
 sytrsg_rsaafrdw BINARY(8), \
 sytrsg_rsaafrib INT(1) UNSIGNED, \
 sytrsg_rsaafriu BINARY(8), \
 sytrsg_rsacalct BINARY(8), \
 sytrsg_rsasng2g BINARY(8), \
 sytrsg_rsasngav INT(1) UNSIGNED, \
 sytrsg_rsaltdb1 INT(1) UNSIGNED, \
 sytrsg_rsaltda1 INT(1) UNSIGNED, \
 sytrsg_rsaltdd1 INT(1) UNSIGNED, \
 sytrsg_rsaltdc1 INT(1) UNSIGNED, \
 sytrsg_rsaltdb2 INT(1) UNSIGNED, \
 sytrsg_rsaltda2 INT(1) UNSIGNED, \
 sytrsg_rsaltdd2 INT(1) UNSIGNED, \
 sytrsg_rsaltdc2 INT(1) UNSIGNED, \
 sytrsg_rsaltdbe INT(1) UNSIGNED, \
 sytrsg_rsaltdae INT(1) UNSIGNED, \
 sytrsg_rsaltdde INT(1) UNSIGNED, \
 sytrsg_rsaltdce INT(1) UNSIGNED, \
 sytrsg_rsadrmb1 INT(1) UNSIGNED, \
 sytrsg_rsadrma1 INT(1) UNSIGNED, \
 sytrsg_rsadrmd1 INT(1) UNSIGNED, \
 sytrsg_rsadrmc1 INT(1) UNSIGNED, \
 sytrsg_rsadrmb2 INT(1) UNSIGNED, \
 sytrsg_rsadrma2 INT(1) UNSIGNED, \
 sytrsg_rsadrmd2 INT(1) UNSIGNED, \
 sytrsg_rsadrmc2 INT(1) UNSIGNED, \
 sytrsg_rsadrmbe INT(1) UNSIGNED, \
 sytrsg_rsadrmae INT(1) UNSIGNED, \
 sytrsg_rsadrmde INT(1) UNSIGNED, \
 sytrsg_rsadrmce INT(1) UNSIGNED, \
 sytrsg_rsaelgb1 INT(1) UNSIGNED, \
 sytrsg_rsaelga1 INT(1) UNSIGNED, \
 sytrsg_rsaelgd1 INT(1) UNSIGNED, \
 sytrsg_rsaelgc1 INT(1) UNSIGNED, \
 sytrsg_rsaelgb2 INT(1) UNSIGNED, \
 sytrsg_rsaelga2 INT(1) UNSIGNED, \
 sytrsg_rsaelgd2 INT(1) UNSIGNED, \
 sytrsg_rsaelgc2 INT(1) UNSIGNED, \
 sytrsg_rsaelgbe INT(1) UNSIGNED, \
 sytrsg_rsaelgae INT(1) UNSIGNED, \
 sytrsg_rsaelgde INT(1) UNSIGNED, \
 sytrsg_rsaelgce INT(1) UNSIGNED, \
 sytrsg_rsadspb1 INT(1) UNSIGNED, \
 sytrsg_rsadspa1 INT(1) UNSIGNED, \
 sytrsg_rsadspd1 INT(1) UNSIGNED, \
 sytrsg_rsadspc1 INT(1) UNSIGNED, \
 sytrsg_rsadspb2 INT(1) UNSIGNED, \
 sytrsg_rsadspa2 INT(1) UNSIGNED, \
 sytrsg_rsadspd2 INT(1) UNSIGNED, \
 sytrsg_rsadspc2 INT(1) UNSIGNED, \
 sytrsg_rsadspbe INT(1) UNSIGNED, \
 sytrsg_rsadspae INT(1) UNSIGNED, \
 sytrsg_rsadspde INT(1) UNSIGNED, \
 sytrsg_rsadspce INT(1) UNSIGNED, \
 sytrsg_rsashrb1 INT(1) UNSIGNED, \
 sytrsg_rsashra1 INT(1) UNSIGNED, \
 sytrsg_rsashrd1 INT(1) UNSIGNED, \
 sytrsg_rsashrc1 INT(1) UNSIGNED, \
 sytrsg_rsashrb2 INT(1) UNSIGNED, \
 sytrsg_rsashra2 INT(1) UNSIGNED, \
 sytrsg_rsashrd2 INT(1) UNSIGNED, \
 sytrsg_rsashrc2 INT(1) UNSIGNED, \
 sytrsg_rsashrbe INT(1) UNSIGNED, \
 sytrsg_rsashrae INT(1) UNSIGNED, \
 sytrsg_rsashrde INT(1) UNSIGNED, \
 sytrsg_rsashrce INT(1) UNSIGNED, \
 sytrsg_rsaresac INT(1) UNSIGNED, \
 sytrsg_rsaresbc INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d0r4 =
 "CREATE TABLE IF NOT EXISTS d0r4 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sytrsp_pfxcpuad SMALLINT(1) UNSIGNED, \
 sytrsp_plsstlfr INT(1) UNSIGNED, \
 sytrsp_plsprqdf INT(1) UNSIGNED, \
 sytrsp_plsshrrd INT(1) UNSIGNED, \
 sytrsp_plsalemp INT(1) UNSIGNED, \
 sytrsp_plsnocmp INT(1) UNSIGNED, \
 sytrsp_plsmvb2g INT(1) UNSIGNED, \
 sytrsp_plsalemg INT(1) UNSIGNED, \
 sytrsp_plsgclem INT(1) UNSIGNED, \
 sytrsp_plsmvabv INT(1) UNSIGNED, \
 sytrsp_pfxcputy TINYINT(1) UNSIGNED, \
 sytrsp_plsalecl INT(1) UNSIGNED, \
 sytrsp_plsalecg INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d0r5 =
 "CREATE TABLE IF NOT EXISTS d0r5 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sytxsp_pfxcpuad SMALLINT(1) UNSIGNED, \
 sytxsp_pfxpgin INT(1) UNSIGNED, \
 sytxsp_plspgin INT(1) UNSIGNED, \
 sytxsp_plspgout INT(1) UNSIGNED, \
 sytxsp_plspgxrd INT(1) UNSIGNED, \
 sytxsp_plspgxwt INT(1) UNSIGNED, \
 sytxsp_plspgmrx INT(1) UNSIGNED, \
 sytxsp_plspgmrd INT(1) UNSIGNED, \
 sytxsp_pfxcputy TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d0r6 =
 "CREATE TABLE IF NOT EXISTS d0r6 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sytasg_cal90ful INT(1) UNSIGNED, \
 sytasg_cal91ful INT(1) UNSIGNED, \
 sytasg_calslta1 INT(1) UNSIGNED, \
 sytasg_calslti1 INT(1) UNSIGNED, \
 sytasg_calslta2 INT(1) UNSIGNED, \
 sytasg_calslti2 INT(1) UNSIGNED, \
 sytasg_syssfcrt INT(1) UNSIGNED, \
 sytasg_syssfpur INT(1) UNSIGNED, \
 sytasg_caltotm1 INT(1) UNSIGNED, \
 sytasg_calavgm1 INT(1) UNSIGNED, \
 sytasg_caltotm2 INT(1) UNSIGNED, \
 sytasg_calavgm2 INT(1) UNSIGNED, \
 sytasg_caldmpav INT(1) UNSIGNED, \
 sytasg_caldmpiu INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d0r7 =
 "CREATE TABLE IF NOT EXISTS d0r7 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sytshs_systanss INT(1) UNSIGNED, \
 sytshs_systadcs INT(1) UNSIGNED, \
 sytshs_rsashare INT(1) UNSIGNED, \
 sytshs_calnumsa INT(1) UNSIGNED, \
 sytshs_rsactshr INT(1) UNSIGNED, \
 sytshs_vmdsforo INT(1) UNSIGNED, \
 sytshs_vmdsfore INT(1) UNSIGNED, \
 sytshs_qdgsyslm INT(1) UNSIGNED, \
 sytshs_qdgusrlm INT(1) UNSIGNED, \
 sytshs_qdgsysca INT(1) UNSIGNED, \
 sytshs_qdglkcnt INT(1) UNSIGNED, \
 sytshs_qdgdisks INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d0r9 =
    "CREATE TABLE IF NOT EXISTS d0r9 (\
        id BIGINT AUTO_INCREMENT, \
        time TIMESTAMP, \
        sytcpc_hfcount INT(1) UNSIGNED, \
        sytcpc_hfchbusy BLOB, \
        sytcpc_hfchsim BLOB, \
    PRIMARY KEY (id)) ENGINE=ARCHIVE";

//=============================== TODO
const char *query_create_d0r10 =
    "CREATE TABLE IF NOT EXISTS d0r10 (\
        id BIGINT AUTO_INCREMENT, \
        time TIMESTAMP, \
        
    PRIMARY KEY (id)) ENGINE=ARCHIVE";
//======================================




const char *query_create_d0r11 =
 "CREATE TABLE IF NOT EXISTS d0r11 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sytcom_pfxcpuad SMALLINT(1) UNSIGNED, \
 sytcom_plsisevm INT(1) UNSIGNED, \
 sytcom_plsisema INT(1) UNSIGNED, \
 sytcom_plsisem INT(1) UNSIGNED, \
 sytcom_plsisera INT(1) UNSIGNED, \
 sytcom_plsisebl INT(1) UNSIGNED, \
 sytcom_plsisemo INT(1) UNSIGNED, \
 sytcom_plsistma INT(1) UNSIGNED, \
 sytcom_plsistvm INT(1) UNSIGNED, \
 sytcom_plsistm INT(1) UNSIGNED, \
 sytcom_plsistra INT(1) UNSIGNED, \
 sytcom_plsistbl INT(1) UNSIGNED, \
 sytcom_plsistmo INT(1) UNSIGNED, \
 sytcom_plsisuvm INT(1) UNSIGNED, \
 sytcom_plsisuma INT(1) UNSIGNED, \
 sytcom_plsisum INT(1) UNSIGNED, \
 sytcom_plsisura INT(1) UNSIGNED, \
 sytcom_plsisubl INT(1) UNSIGNED, \
 sytcom_plsisumo INT(1) UNSIGNED, \
 sytcom_plsvsevm INT(1) UNSIGNED, \
 sytcom_plsvstvm INT(1) UNSIGNED, \
 sytcom_plsvsuvm INT(1) UNSIGNED, \
 sytcom_plsisecc INT(1) UNSIGNED, \
 sytcom_plsistcc INT(1) UNSIGNED, \
 sytcom_plsisucc INT(1) UNSIGNED, \
 sytcom_plsisesi INT(1) UNSIGNED, \
 sytcom_plsistsi INT(1) UNSIGNED, \
 sytcom_plsisusi INT(1) UNSIGNED, \
 sytcom_plsisesp INT(1) UNSIGNED, \
 sytcom_plsistsp INT(1) UNSIGNED, \
 sytcom_plsisusp INT(1) UNSIGNED, \
 sytcom_plsisesy INT(1) UNSIGNED, \
 sytcom_plsistsy INT(1) UNSIGNED, \
 sytcom_plsisusy INT(1) UNSIGNED, \
 sytcom_plsiseac INT(1) UNSIGNED, \
 sytcom_plsistac INT(1) UNSIGNED, \
 sytcom_plsisuac INT(1) UNSIGNED, \
 sytcom_plsiselo INT(1) UNSIGNED, \
 sytcom_plsistlo INT(1) UNSIGNED, \
 sytcom_plsisulo INT(1) UNSIGNED, \
 sytcom_plsisecr INT(1) UNSIGNED, \
 sytcom_plsistcr INT(1) UNSIGNED, \
 sytcom_plsisucr INT(1) UNSIGNED, \
 sytcom_plsiseid INT(1) UNSIGNED, \
 sytcom_plsistid INT(1) UNSIGNED, \
 sytcom_plsisuid INT(1) UNSIGNED, \
 sytcom_plsisecf INT(1) UNSIGNED, \
 sytcom_plsistcf INT(1) UNSIGNED, \
 sytcom_plsisucf INT(1) UNSIGNED, \
 sytcom_plsiucvt INT(1) UNSIGNED, \
 sytcom_pfxcputy TINYINT(1) UNSIGNED, \
 sytcom_plsisevs INT(1) UNSIGNED, \
 sytcom_plsistvs INT(1) UNSIGNED, \
 sytcom_plsisuvs INT(1) UNSIGNED, \
 sytcom_plsiseas INT(1) UNSIGNED, \
 sytcom_plsistas INT(1) UNSIGNED, \
 sytcom_plsisuas INT(1) UNSIGNED, \
 sytcom_plsisesc INT(1) UNSIGNED, \
 sytcom_plsistsc INT(1) UNSIGNED, \
 sytcom_plsisusc INT(1) UNSIGNED, \
 sytcom_plsiseve INT(1) UNSIGNED, \
 sytcom_plsistve INT(1) UNSIGNED, \
 sytcom_plsisuve INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d0r12 =
 "CREATE TABLE IF NOT EXISTS d0r12 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sytuwt_caltidl INT(1) UNSIGNED, \
 sytuwt_caltsvm INT(1) UNSIGNED, \
 sytuwt_caliowt INT(1) SIGNED, \
 sytuwt_calwtpag INT(1) SIGNED, \
 sytuwt_calcfwt INT(1) SIGNED, \
 sytuwt_calsimwt INT(1) SIGNED, \
 sytuwt_calcpuwt INT(1) SIGNED, \
 sytuwt_calcpurn INT(1) SIGNED, \
 sytuwt_calothr INT(1) SIGNED, \
 sytuwt_calqdisp INT(1) SIGNED, \
 sytuwt_calelsvm INT(1) SIGNED, \
 sytuwt_srmcelig SMALLINT(1) UNSIGNED, \
 sytuwt_srmdsvmw INT(1) SIGNED, \
 sytuwt_calioact INT(1) UNSIGNED, \
 sytuwt_calllist INT(1) UNSIGNED, \
 sytuwt_calllcp INT(1) UNSIGNED, \
 sytuwt_calllzap INT(1) UNSIGNED, \
 sytuwt_calllifl INT(1) UNSIGNED, \
 sytuwt_calllzip INT(1) UNSIGNED, \
 sytuwt_calcfcp INT(1) SIGNED, \
 sytuwt_calcfzap INT(1) SIGNED, \
 sytuwt_calcfifl INT(1) SIGNED, \
 sytuwt_calcfzip INT(1) SIGNED, \
 sytuwt_calswcp INT(1) SIGNED, \
 sytuwt_calswzap INT(1) SIGNED, \
 sytuwt_calswifl INT(1) SIGNED, \
 sytuwt_calswzip INT(1) SIGNED, \
 sytuwt_calcwcp INT(1) SIGNED, \
 sytuwt_calcwzap INT(1) SIGNED, \
 sytuwt_calcwifl INT(1) SIGNED, \
 sytuwt_calcwzip INT(1) SIGNED, \
 sytuwt_calcrcp INT(1) SIGNED, \
 sytuwt_calcrzap INT(1) SIGNED, \
 sytuwt_calcrifl INT(1) SIGNED, \
 sytuwt_calcrzip INT(1) SIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d0r13 =
 "CREATE TABLE IF NOT EXISTS d0r13 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sytscp_pfxcpuad SMALLINT(1) UNSIGNED, \
 sytscp_plseqkad SMALLINT(1) UNSIGNED, \
 sytscp_plsefrc1 SMALLINT(1) UNSIGNED, \
 sytscp_plsefrc2 SMALLINT(1) UNSIGNED, \
 sytscp_plsefrc3 SMALLINT(1) UNSIGNED, \
 sytscp_plsdspcn INT(1) UNSIGNED, \
 sytscp_pfxcputy TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d0r14 =
 "CREATE TABLE IF NOT EXISTS d0r14 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sytxsg_xstxbget INT(1) UNSIGNED, \
 sytxsg_xstxbrel INT(1) UNSIGNED, \
 sytxsg_xstusrsh INT(1) UNSIGNED, \
 sytxsg_xstctxav BINARY(8), \
 sytxsg_xstcppar BINARY(8), \
 sytxsg_hcpmdcpy INT(1) UNSIGNED, \
 sytxsg_hcpmdcpn INT(1) UNSIGNED, \
 sytxsg_hcpmdcpr INT(1) UNSIGNED, \
 sytxsg_hcpmdcpw INT(1) UNSIGNED, \
 sytxsg_hcpmdcac INT(1) UNSIGNED, \
 sytxsg_hcpmdcne INT(1) UNSIGNED, \
 sytxsg_hcpmdcex INT(1) UNSIGNED, \
 sytxsg_hcpmdcli INT(1) UNSIGNED, \
 sytxsg_calmdcau INT(1) UNSIGNED, \
 sytxsg_hcpmdcis INT(1) UNSIGNED, \
 sytxsg_hcpmdcqc INT(1) UNSIGNED, \
 sytxsg_hcpmdcxg INT(1) UNSIGNED, \
 sytxsg_hcpmdcxr INT(1) UNSIGNED, \
 sytxsg_hcpmdctr INT(1) UNSIGNED, \
 sytxsg_hcpmdcia INT(1) UNSIGNED, \
 sytxsg_hcpmdcib INT(1) UNSIGNED, \
 sytxsg_hcpmdcit INT(1) UNSIGNED, \
 sytxsg_tcmxidsz INT(1) UNSIGNED, \
 sytxsg_tcmxsmin INT(1) UNSIGNED, \
 sytxsg_tcmstlxs INT(1) UNSIGNED, \
 sytxsg_xstavgag INT(1) UNSIGNED, \
 sytxsg_hcpstpxb SMALLINT(1) UNSIGNED, \
 sytxsg_tcmfshvm INT(1) UNSIGNED, \
 sytxsg_tcmrdct INT(1) UNSIGNED, \
 sytxsg_tcmpin4k INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d0r15 =
 "CREATE TABLE IF NOT EXISTS d0r15 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sytcug_lcutnpar TINYINT(1) UNSIGNED, \
 sytcug_lcutflag TINYINT(1) UNSIGNED, \
 sytcug_lcutslce SMALLINT(1) UNSIGNED, \
 sytcug_lcutpcct SMALLINT(1) UNSIGNED, \
 sytcug_lpnumber SMALLINT(1) UNSIGNED, \
 sytcug_cpuchar TINYINT(1) UNSIGNED, \
 sytcug_cpucount SMALLINT(1) UNSIGNED, \
 sytcug_cpucfgct SMALLINT(1) UNSIGNED, \
 sytcug_cpustnby SMALLINT(1) UNSIGNED, \
 sytcug_cpuresvd SMALLINT(1) UNSIGNED, \
 sytcug_lparname CHAR(8), \
 sytcug_lparcaf INT(1) UNSIGNED, \
 sytcug_cpudedct SMALLINT(1) UNSIGNED, \
 sytcug_cpushard SMALLINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d0r19 =
 "CREATE TABLE IF NOT EXISTS d0r19 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sytsyg_xctmsact BINARY(8), \
 sytsyg_ftrdone INT(1) UNSIGNED, \
 sytsyg_ftrabort INT(1) UNSIGNED, \
 sytsyg_ftrnotel INT(1) UNSIGNED, \
 sytsyg_ftrwrite INT(1) UNSIGNED, \
 sytsyg_ctndone INT(1) UNSIGNED, \
 sytsyg_ctnabort INT(1) UNSIGNED, \
 sytsyg_ctnnotel INT(1) UNSIGNED, \
 sytsyg_scpcapab INT(1) UNSIGNED, \
 sytsyg_cpucapab INT(1) UNSIGNED, \
 sytsyg_cpucount SMALLINT(1) UNSIGNED, \
 sytsyg_cpucfgct SMALLINT(1) UNSIGNED, \
 sytsyg_cpustnby SMALLINT(1) UNSIGNED, \
 sytsyg_cpuresvd SMALLINT(1) UNSIGNED, \
 sytsyg_vl3dbct TINYINT(1) UNSIGNED, \
 sytsyg_vl3count SMALLINT(1) UNSIGNED, \
 sytsyg_vl3cfgct SMALLINT(1) UNSIGNED, \
 sytsyg_vl3stnby SMALLINT(1) UNSIGNED, \
 sytsyg_vl3resvd SMALLINT(1) UNSIGNED, \
 sytsyg_vl3mname CHAR(8), \
 sytsyg_vl3caf INT(1) UNSIGNED, \
 sytsyg_vl3cpnam CHAR(16), \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d0r21 =
 "CREATE TABLE IF NOT EXISTS d0r21 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sytsxg_sxssize INT(1) UNSIGNED, \
 sytsxg_rsasxavl INT(1) UNSIGNED, \
 sytsxg_rsasxbka INT(1) UNSIGNED, \
 sytsxg_rsasxbkb INT(1) UNSIGNED, \
 sytsxg_rsasxusd INT(1) UNSIGNED, \
 sytsxg_rsasxucp INT(1) UNSIGNED, \
 sytsxg_rsasxuid INT(1) UNSIGNED, \
 sytsxg_rsasxufs INT(1) UNSIGNED, \
 sytsxg_rsasxufg INT(1) UNSIGNED, \
 sytsxg_rsasxali INT(1) UNSIGNED, \
 sytsxg_rsasxnop INT(1) UNSIGNED, \
 sytsxg_rsasxcla INT(1) UNSIGNED, \
 sytsxg_rsasxqct INT(1) UNSIGNED, \
 sytsxg_rsasxact INT(1) UNSIGNED, \
 sytsxg_rsasxbct INT(1) UNSIGNED, \
 sytsxg_rsarsvsy INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d0r22 =
 "CREATE TABLE IF NOT EXISTS d0r22 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sytsxp_pfxcpuad SMALLINT(1) UNSIGNED, \
 sytsxp_plssxrep INT(1) UNSIGNED, \
 sytsxp_plssxacc INT(1) UNSIGNED, \
 sytsxp_plssxarc INT(1) UNSIGNED, \
 sytsxp_plssxaqc INT(1) UNSIGNED, \
 sytsxp_plsspfsc INT(1) UNSIGNED, \
 sytsxp_plsspgpc INT(1) UNSIGNED, \
 sytsxp_plsspgcc INT(1) UNSIGNED, \
 sytsxp_plsspgct INT(1) UNSIGNED, \
 sytsxp_plssprpc INT(1) UNSIGNED, \
 sytsxp_plssprcc INT(1) UNSIGNED, \
 sytsxp_plssprct INT(1) UNSIGNED, \
 sytsxp_plssprqc INT(1) UNSIGNED, \
 sytsxp_plssprqt INT(1) UNSIGNED, \
 sytsxp_plsspgfc INT(1) UNSIGNED, \
 sytsxp_plssprfc INT(1) UNSIGNED, \
 sytsxp_pfxcputy TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

//DOMAIN-1's TABLE
const char *query_create_d1r1 =
 "CREATE TABLE IF NOT EXISTS d1r1 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP UNIQUE, \
 mtrepr_edomains TINYINT(1) UNSIGNED, \
 ibm TINYINT(1) UNSIGNED, \
 mtrepr_config SMALLINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d1r3=
 "CREATE TABLE IF NOT EXISTS d1r3 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 mtrsus_lostrcct INT(1) UNSIGNED, \
 PRIMARY KEY (id), \
 INDEX (id)) ENGINE=ARCHIVE";

const char *query_create_d1r4 =
 "CREATE TABLE IF NOT EXISTS d1r4 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP UNIQUE, \
 mtrsys_hcpcpepp BINARY(8), \
 mtrsys_hcpcpeid CHAR(8), \
 mtrsys_systodst TIMESTAMP, \
 mtrsys_systerm TIMESTAMP, \
 mtrsys_sysdate CHAR(8), \
 mtrsys_sysabncd BINARY(8), \
 mtrsys_syszone INT(1) UNSIGNED, \
 mtrsys_calflgs TINYINT(1) UNSIGNED, \
 mtrsys_sysvrfsg TINYINT(1) UNSIGNED, \
 mtrsys_calflg2 TINYINT(1) UNSIGNED, \
 mtrsys_systmid CHAR(8), \
 mtrsys_sysckvol CHAR(6), \
 mtrsys_syswmvol CHAR(6), \
 mtrsys_sysmtype CHAR(4), \
 mtrsys_sysmmodl CHAR(16), \
 mtrsys_sysmseqc CHAR(16), \
 mtrsys_sysmpom CHAR(4), \
 mtrsys_lpnumber SMALLINT(1) UNSIGNED, \
 mtrsys_cpuchar TINYINT(1) UNSIGNED, \
 mtrsys_cpucount SMALLINT(1) UNSIGNED, \
 mtrsys_cpucfgct SMALLINT(1) UNSIGNED, \
 mtrsys_cpustnby SMALLINT(1) UNSIGNED, \
 mtrsys_cpuresvd SMALLINT(1) UNSIGNED, \
 mtrsys_lparname CHAR(8), \
 mtrsys_lparcaf INT(1) UNSIGNED, \
 mtrsys_cpudedct SMALLINT(1) UNSIGNED, \
 mtrsys_cpushard SMALLINT(1) UNSIGNED, \
 mtrsys_cpucapab INT(1) UNSIGNED, \
 mtrsys_scpcapab INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d1r5=
 "CREATE TABLE IF NOT EXISTS d1r5 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 mtrprp_pfxcpuad SMALLINT(1) UNSIGNED, \
 mtrprp_pfxidmdl CHAR(2), \
 mtrprp_pfxidser CHAR(3), \
 mtrprp_calflags TINYINT(1) UNSIGNED, \
 mtrprp_pcccsu TINYINT(1) UNSIGNED, \
 mtrprp_pfxidver TINYINT(1) UNSIGNED, \
 mtrprp_pfxtype TINYINT(1) UNSIGNED, \
 mtrprp_caluded CHAR(8), \
 mtrprp_pfxcputy TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d1r9=
 "CREATE TABLE IF NOT EXISTS d1r9 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 mtrspr_interval INT(1) SIGNED, \
 mtrspr_hfrate INT(1) SIGNED, \
 mtrspr_sdomains TINYINT(1) UNSIGNED, \
 ibm TINYINT(1) UNSIGNED, \
 mtrspr_hdomains TINYINT(1) UNSIGNED, \
 mtrspr_config SMALLINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d1r10 =
 "CREATE TABLE IF NOT EXISTS d1r10 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 mtrscm_caltod TIMESTAMP, \
 mtrscm_calbyct INT(1) UNSIGNED, \
 mtrscm_calcmd VARCHAR(256), \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d1r11 =
    "CREATE TABLE IF NOT EXISTS d1r11 (\
        id BIGINT AUTO_INCREMENT, \
        time TIMESTAMP, \
    PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d1r12 =
 "CREATE TABLE IF NOT EXISTS d1r12 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d1r13 =
 "CREATE TABLE IF NOT EXISTS d1r13 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

////

const char *query_create_d1r15 =
    "CREATE TABLE IF NOT EXISTS d1r15 (\
        id BIGINT AUTO_INCREMENT, \
        time TIMESTAMP, \
        mtrusr_vmduser CHAR(8), \
        mtrusr_vmdcpuad SMALLINT UNSIGNED, \
        __u8 mtrusr_vmdmode TINYINT UNSIGNED, \
        __u8 mtrusr_vmdcpuct TINYINT UNSIGNED, \
        __u8 mtrusr_calstat TINYINT UNSIGNED, \
        __u8 mtrusr_calmode TINYINT UNSIGNED, \
        __u8 mtrusr_vmdstype TINYINT UNSIGNED, \
        __u8 mtrusr_calsharf TINYINT UNSIGNED, \
        __u32 mtrusr_vmdrelsh INT UNSIGNED, \
        __u32 mtrusr_vmdabssh INT UNSIGNED, \
        __u32 mtrusr_vmdssize INT UNSIGNED, \
        __u8 mtrusr_vmdactno[8];
        __u8 mtrusr_vmdgrpn[8];
        __u32 mtrusr_vmdmxrvp INT UNSIGNED, \
        __u64 mtrusr_caltodon BIGINT UNSIGNED, \
        __u8 mtrusr_vmdbyval[8];
        __u32 mtrusr_vmdmxshr INT UNSIGNED, \
        __u64 mtrusr_ascdefsz BIGINT UNSIGNED, \
        __u8 mtrusr_caldefhi[4] INT UNSIGNED, \
        __u8 mtrusr_caldeflo[4] INT UNSIGNED, \
        __u32 mtrusr_calcpct INT UNSIGNED, \
        __u32 mtrusr_calzipct INT UNSIGNED, \
        __u32 mtrusr_calzapct INT UNSIGNED, \
        __u32 mtrusr_califlct INT UNSIGNED, \
        __u8 mtrusr_vmdcfgem TINYINT UNSIGNED, \
        __u8 mtrusr_vmdpust TINYINT UNSIGNED, \
    PRIMARY KEY (id)) ENGINE=ARCHIVE";

 const char *query_create_d1r16 =
    "CREATE TABLE IF NOT EXISTS d1r16 (\
        id BIGINT AUTO_INCREMENT, \
        time TIMESTAMP, \
        mtrsch_srmbiasi INT UNSIGNED, \
        __u8 mtrsch_srmtslic[8];
        mtrsch_srmtshot[8];
        mtrsch_srmbiasd SMALLINT UNSIGNED, \
        mtrsch_srmldgus SMALLINT UNSIGNED, \
        mtrsch_srmp1ldg INT UNSIGNED, \
        mtrsch_srmp2ldg INT UNSIGNED, \
        mtrsch_srmp3ldg INT UNSIGNED, \
        mtrsch_srmldgcp INT UNSIGNED, \
        mtrsch_srmp1wss INT UNSIGNED, \
        mtrsch_srmp2wss INT UNSIGNED, \
        mtrsch_srmp3wss INT UNSIGNED, \
        mtrsch_srmwssmp INT UNSIGNED, \
        mtrsch_srml1dsp INT UNSIGNED, \
        mtrsch_srml2dsp INT UNSIGNED, \
        mtrsch_srml3dsp INT UNSIGNED, \
        mtrsch_srmxpctg INT UNSIGNED, \
        mtrsch_srmflags TINYINT UNSIGNED, \
    PRIMARY KEY (id)) ENGINE=ARCHIVE";

 ///

const char *query_create_d1r17 =
 "CREATE TABLE IF NOT EXISTS d1r17 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 mtrxsg_xstotalb BINARY(8), \
 mtrxsg_sysxtsiz BINARY(8), \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d1r18 =
 "CREATE TABLE IF NOT EXISTS d1r18 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 mtrccc_cpucapab INT(1) UNSIGNED, \
 mtrccc_scpcapab INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d1r19 =
 "CREATE TABLE IF NOT EXISTS d1r19 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 mtrqdc_rdevdev SMALLINT(1) UNSIGNED, \
 mtrqdc_vmduser CHAR(8), \
 mtrqdc_vdevdev SMALLINT(1) UNSIGNED, \
 mtrqdc_qdiofmt SMALLINT(1) UNSIGNED, \
 mtrqdc_qdinpct SMALLINT(1) UNSIGNED, \
 mtrqdc_qdioutct SMALLINT(1) UNSIGNED, \
 mtrqdc_status TINYINT(1) UNSIGNED, \
 mtrqdc_qdiocsgr INT(1) UNSIGNED, \
 mtrqdc_qdiocsgw INT(1) UNSIGNED, \
 mtrqdc_qdiocsgs INT(1) UNSIGNED, \
 mtrqdc_rdevvssr INT(1) UNSIGNED, \
 mtrqdc_rdevvssw INT(1) UNSIGNED, \
 mtrqdc_rdevvsss INT(1) UNSIGNED, \
 mtrqdc_bftoa BIGINT(1) UNSIGNED, \
 mtrqdc_bytoa BIGINT(1) UNSIGNED, \
 mtrqdc_bffra BIGINT(1) UNSIGNED, \
 mtrqdc_byfra BIGINT(1) UNSIGNED, \
 mtrqdc_rdevvsin INT(1) UNSIGNED, \
 mtrqdc_rdevvsir INT(1) UNSIGNED, \
 mtrqdc_rdevvsid INT(1) UNSIGNED, \
 mtrqdc_qsbsqbvm INT(1) UNSIGNED, \
 mtrqdc_qsbsqbpv INT(1) UNSIGNED, \
 mtrqdc_qsbeqbvm INT(1) UNSIGNED, \
 mtrqdc_qsbeqbpv INT(1) UNSIGNED, \
 mtrqdc_qsblock INT(1) UNSIGNED, \
 mtrqdc_qsbfobx INT(1) UNSIGNED, \
 mtrqdc_qsbolck INT(1) UNSIGNED, \
 mtrqdc_qsbsigwt INT(1) UNSIGNED, \
 mtrqdc_qsbsigrt INT(1) UNSIGNED, \
 mtrqdc_qsbsiglt INT(1) UNSIGNED, \
 mtrqdc_sumofpin INT(1) UNSIGNED, \
 mtrqdc_sumunpin INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d1r20=
 "CREATE TABLE IF NOT EXISTS d1r20 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 mtrhpp_hppoolnm SMALLINT(1) UNSIGNED, \
 mtrhpp_hpptoken SMALLINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";



//DOMAIN-2's TABLE
const char *query_create_d2r1 =
 "CREATE TABLE IF NOT EXISTS d2r1 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP UNIQUE, \
 sclrdb_vmduser CHAR(8), \
 sclrdb_calflags TINYINT(1) UNSIGNED, \
 sclrdb_rdevsid INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d2r2 =
 "CREATE TABLE IF NOT EXISTS d2r2 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP UNIQUE, \
 sclrdc_vmduser CHAR(8), \
 sclrdc_calflags TINYINT(1) UNSIGNED, \
 sclrdc_rdevsid INT(1) UNSIGNED, \
 sclrdc_calbyct INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d2r3 =
 "CREATE TABLE IF NOT EXISTS d2r3 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP UNIQUE, \
 sclwrr_vmduser CHAR(8), \
 sclwrr_calflags TINYINT(1) UNSIGNED, \
 sclwrr_rdevsid INT(1) UNSIGNED, \
 sclwrr_calbyct INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d2r4 =
    "CREATE TABLE IF NOT EXISTS d2r4 (\
        id BIGINT AUTO_INCREMENT, \
        time TIMESTAMP, \

    PRIMARY KEY (id)) ENGINE=ARCHIVE";
const char *query_create_d2r5 =
    "CREATE TABLE IF NOT EXISTS d2r5 (\
        id BIGINT AUTO_INCREMENT, \
        time TIMESTAMP, \

    PRIMARY KEY (id)) ENGINE=ARCHIVE";
const char *query_create_d2r6 =
    "CREATE TABLE IF NOT EXISTS d2r6 (\
        id BIGINT AUTO_INCREMENT, \
        time TIMESTAMP, \

    PRIMARY KEY (id)) ENGINE=ARCHIVE";
const char *query_create_d2r7 =
    "CREATE TABLE IF NOT EXISTS d2r7 (\
        id BIGINT AUTO_INCREMENT, \
        time TIMESTAMP, \

    PRIMARY KEY (id)) ENGINE=ARCHIVE";
const char *query_create_d2r8 =
    "CREATE TABLE IF NOT EXISTS d2r8 (\
        id BIGINT AUTO_INCREMENT, \
        time TIMESTAMP, \

    PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d2r9=
 "CREATE TABLE IF NOT EXISTS d2r9 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sclshr_vmduser CHAR(8), \
 sclshr_vmdrelsh INT(1) UNSIGNED, \
 sclshr_vmdabssh INT(1) UNSIGNED, \
 sclshr_calsharf TINYINT(1) UNSIGNED, \
 sclshr_vmdmxshr INT(1) UNSIGNED, \
 sclshr_vmdcfgem TINYINT(1) UNSIGNED, \
 sclshr_vmdpust TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d2r10=
 "CREATE TABLE IF NOT EXISTS d2r10 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sclsqd_vmduser CHAR(8), \
 sclsqd_calflag1 TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d2r11=
 "CREATE TABLE IF NOT EXISTS d2r11 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 scliop_vmduser CHAR(8), \
 scliop_ipqupr1 INT(1) UNSIGNED, \
 scliop_newrqlo TINYINT(1) UNSIGNED, \
 scliop_newrqhi TINYINT(1) UNSIGNED, \
 scliop_ipqx0 TINYINT(1) UNSIGNED, \
 scliop_sysiopq INT(1) UNSIGNED, \
 scliop_sysiopqh TINYINT(1) UNSIGNED, \
 scliop_sysioplo TINYINT(1) UNSIGNED, \
 scliop_sysiophi TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d2r12=
 "CREATE TABLE IF NOT EXISTS d2r12 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 sclsca_vmduser CHAR(8), \
 sclsca_vmdcfgem TINYINT(1) UNSIGNED, \
 sclsca_vmdpust TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

//DOMAIN-3's TABLE
const char *query_create_d3r1=
 "CREATE TABLE IF NOT EXISTS d3r1 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 storsg_calssubt INT(1) UNSIGNED, \
 storsg_rsasavfr INT(1) UNSIGNED, \
 storsg_rsamaxpp INT(1) UNSIGNED, \
 storsg_rsacplok INT(1) UNSIGNED, \
 storsg_rsaavllt INT(1) UNSIGNED, \
 storsg_rsaavlht INT(1) UNSIGNED, \
 storsg_xstbprct INT(1) UNSIGNED, \
 storsg_xstsrgct INT(1) UNSIGNED, \
 storsg_xstmrabi INT(1) UNSIGNED, \
 storsg_xstsrabi INT(1) UNSIGNED, \
 storsg_xstsrsct INT(1) UNSIGNED, \
 storsg_calptrrt INT(1) UNSIGNED, \
 storsg_calcaafp INT(1) UNSIGNED, \
 storsg_calascut INT(1) UNSIGNED, \
 storsg_rsasxcpl INT(1) UNSIGNED, \
 storsg_rsasxcla INT(1) UNSIGNED, \
 storsg_rsaavlhg INT(1) UNSIGNED, \
 storsg_rsaavllg INT(1) UNSIGNED, \
 storsg_rsacplkg INT(1) UNSIGNED, \
 storsg_calssubg INT(1) UNSIGNED, \
 storsg_rsarsvsy INT(1) UNSIGNED, \
 storsg_rsacallt BINARY(8), \
 storsg_rsacalmt BINARY(8), \
 storsg_rsacalut BINARY(8), \
 storsg_rsaafsdw INT(1) UNSIGNED, \
 storsg_rsaafsdb INT(1) UNSIGNED, \
 storsg_rsaafsiu INT(1) UNSIGNED, \
 storsg_rsaafsib INT(1) UNSIGNED, \
 storsg_rsavcbdw INT(1) UNSIGNED, \
 storsg_rsavcbdb INT(1) UNSIGNED, \
 storsg_rsavcbiu INT(1) UNSIGNED, \
 storsg_rsavcbib INT(1) UNSIGNED, \
 storsg_rsavfsdw INT(1) UNSIGNED, \
 storsg_rsavfsiu INT(1) UNSIGNED, \
 storsg_rsa2gdct INT(1) UNSIGNED, \
 storsg_rsafrqwt INT(1) UNSIGNED, \
 storsg_rsafrrda INT(1) UNSIGNED, \
 storsg_rsafrrdc INT(1) UNSIGNED, \
 storsg_rsastlwt INT(1) UNSIGNED, \
 storsg_rsaswg2g INT(1) UNSIGNED, \
 storsg_rsafvmud INT(1) UNSIGNED, \
 storsg_rsafvmub INT(1) UNSIGNED, \
 storsg_rsavmxfr INT(1) UNSIGNED, \
 storsg_rsavmxfb INT(1) UNSIGNED, \
 storsg_rsavmxud INT(1) UNSIGNED, \
 storsg_rsavmxub INT(1) UNSIGNED, \
 storsg_rsasysfr INT(1) UNSIGNED, \
 storsg_rsasysfb INT(1) UNSIGNED, \
 storsg_rsasysud INT(1) UNSIGNED, \
 storsg_rsasysub INT(1) UNSIGNED, \
 storsg_rsaplpct INT(1) UNSIGNED, \
 storsg_rsaplpcb INT(1) UNSIGNED, \
 storsg_rsanpgct INT(1) UNSIGNED, \
 storsg_rsanpghi INT(1) UNSIGNED, \
 storsg_rsanolkl INT(1) UNSIGNED, \
 storsg_rsanolka BINARY(8), \
 storsg_rsasxnop INT(1) UNSIGNED, \
 storsg_rsapptps INT(1) UNSIGNED, \
 storsg_rsapptpf INT(1) UNSIGNED, \
 storsg_rsapptcs INT(1) UNSIGNED, \
 storsg_rsablkgc INT(1) UNSIGNED, \
 storsg_rsafrqmw INT(1) UNSIGNED, \
 storsg_rsafrqdf INT(1) UNSIGNED, \
 storsg_rsafrqdl INT(1) UNSIGNED, \
 storsg_rsaalfmf INT(1) UNSIGNED, \
 storsg_rsaavclt INT(1) UNSIGNED, \
 storsg_rsaavcht INT(1) UNSIGNED, \
 storsg_rsaavclg INT(1) UNSIGNED, \
 storsg_rsaavchg INT(1) UNSIGNED, \
 storsg_rsaemlo INT(1) UNSIGNED, \
 storsg_rsaemhi INT(1) UNSIGNED, \
 storsg_rsaemcpc INT(1) UNSIGNED, \
 storsg_rsaemerg INT(1) UNSIGNED, \
 storsg_rsaemblo INT(1) UNSIGNED, \
 storsg_rsaempty INT(1) UNSIGNED, \
 storsg_rsaemdfr INT(1) UNSIGNED, \
 storsg_rsaswpwt INT(1) UNSIGNED, \
 storsg_rsaswp2g INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d3r2=
 "CREATE TABLE IF NOT EXISTS d3r2 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 storsp_pfxcpuad SMALLINT(1) UNSIGNED, \
 storsp_plspread INT(1) UNSIGNED, \
 storsp_plspnew INT(1) UNSIGNED, \
 storsp_pfxclear INT(1) UNSIGNED, \
 storsp_pfxptrct INT(1) UNSIGNED, \
 storsp_plsreles INT(1) UNSIGNED, \
 storsp_plsretfr INT(1) UNSIGNED, \
 storsp_plsrelfr INT(1) UNSIGNED, \
 storsp_plsalnct INT(1) UNSIGNED, \
 storsp_plsstlwt INT(1) UNSIGNED, \
 storsp_plsltd1 INT(1) UNSIGNED, \
 storsp_plsdorm1 INT(1) UNSIGNED, \
 storsp_plsshar1 INT(1) UNSIGNED, \
 storsp_plselig1 INT(1) UNSIGNED, \
 storsp_plsdisp1 INT(1) UNSIGNED, \
 storsp_plsltd2 INT(1) UNSIGNED, \
 storsp_plsdorm2 INT(1) UNSIGNED, \
 storsp_plselig2 INT(1) UNSIGNED, \
 storsp_plsdisp2 INT(1) UNSIGNED, \
 storsp_plsshare INT(1) UNSIGNED, \
 storsp_plsdorme INT(1) UNSIGNED, \
 storsp_plselige INT(1) UNSIGNED, \
 storsp_plsdispe INT(1) UNSIGNED, \
 storsp_plsltdp1 INT(1) UNSIGNED, \
 storsp_plsdrmp1 INT(1) UNSIGNED, \
 storsp_plsshrp1 INT(1) UNSIGNED, \
 storsp_plsdspp1 INT(1) UNSIGNED, \
 storsp_plselgp1 INT(1) UNSIGNED, \
 storsp_plsltdp2 INT(1) UNSIGNED, \
 storsp_plsdrmp2 INT(1) UNSIGNED, \
 storsp_plsshrp2 INT(1) UNSIGNED, \
 storsp_plsdspp2 INT(1) UNSIGNED, \
 storsp_plselgp2 INT(1) UNSIGNED, \
 storsp_plsdrmpe INT(1) UNSIGNED, \
 storsp_plsshrpe INT(1) UNSIGNED, \
 storsp_plsdsppe INT(1) UNSIGNED, \
 storsp_plselgpe INT(1) UNSIGNED, \
 storsp_plspgdrd INT(1) UNSIGNED, \
 storsp_plspgdwt INT(1) UNSIGNED, \
 storsp_plsalncg INT(1) UNSIGNED, \
 storsp_plsretfg INT(1) UNSIGNED, \
 storsp_plsfsprb INT(1) UNSIGNED, \
 storsp_plsfspra INT(1) UNSIGNED, \
 storsp_plsfsctb INT(1) UNSIGNED, \
 storsp_plsfscta INT(1) UNSIGNED, \
 storsp_plsfretb INT(1) UNSIGNED, \
 storsp_plsfreta INT(1) UNSIGNED, \
 storsp_plsfssgb INT(1) UNSIGNED, \
 storsp_plsfssga INT(1) UNSIGNED, \
 storsp_plsfspgb INT(1) UNSIGNED, \
 storsp_plsfspga INT(1) UNSIGNED, \
 storsp_plsbgcnt INT(1) UNSIGNED, \
 storsp_plsfgctm CHAR(8), \
 storsp_plsfgcnt INT(1) UNSIGNED, \
 storsp_plsfobem INT(1) UNSIGNED, \
 storsp_plsfssra INT(1) UNSIGNED, \
 storsp_plsfssrb INT(1) UNSIGNED, \
 storsp_plsvatcl INT(1) UNSIGNED, \
 storsp_plsupage INT(1) UNSIGNED, \
 storsp_plsvpage INT(1) UNSIGNED, \
 storsp_plspcpag INT(1) UNSIGNED, \
 storsp_plspupag INT(1) UNSIGNED, \
 storsp_plsuprec INT(1) UNSIGNED, \
 storsp_plsessa INT(1) UNSIGNED, \
 storsp_plsltdpe INT(1) UNSIGNED, \
 storsp_plsasfcl INT(1) UNSIGNED, \
 storsp_plsasfcg INT(1) UNSIGNED, \
 storsp_pfxcputy TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";


const char *query_create_d3r3=
 "CREATE TABLE IF NOT EXISTS d3r3 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stoshr_sntname CHAR(8), \
 stoshr_sdfidnum SMALLINT(1) SIGNED, \
 stoshr_sdfcltim INT(1) UNSIGNED, \
 stoshr_sntusrsh SMALLINT(1) UNSIGNED, \
 stoshr_sntusrex SMALLINT(1) UNSIGNED, \
 stoshr_ascctprs INT(1) UNSIGNED, \
 stoshr_sntstrct INT(1) UNSIGNED, \
 stoshr_sntndtct INT(1) UNSIGNED, \
 stoshr_asccspst INT(1) UNSIGNED, \
 stoshr_ascptrsh INT(1) UNSIGNED, \
 stoshr_asccspgr INT(1) UNSIGNED, \
 stoshr_asccspgw INT(1) UNSIGNED, \
 stoshr_asccsxrd INT(1) UNSIGNED, \
 stoshr_asccsxwt INT(1) UNSIGNED, \
 stoshr_asccsmig INT(1) UNSIGNED, \
 stoshr_ascctpgs INT(1) UNSIGNED, \
 stoshr_ascctxbk INT(1) UNSIGNED, \
 stoshr_ascctprg INT(1) UNSIGNED, \
 stoshr_aschllc INT(1) UNSIGNED, \
 stoshr_aschlrc INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";


const char *query_create_d3r4=
 "CREATE TABLE IF NOT EXISTS d3r4 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stoasp_calvser CHAR(6), \
 stoasp_rdevdev SMALLINT(1) UNSIGNED, \
 stoasp_rdevsid INT(1) UNSIGNED, \
 stoasp_calspool INT(1) UNSIGNED, \
 stoasp_calpage INT(1) UNSIGNED, \
 stoasp_expctsrd INT(1) UNSIGNED, \
 stoasp_expctswr INT(1) UNSIGNED, \
 stoasp_expctprd INT(1) UNSIGNED, \
 stoasp_expctpwr INT(1) UNSIGNED, \
 stoasp_expcurqc INT(1) UNSIGNED, \
 stoasp_expctacp INT(1) UNSIGNED, \
 stoasp_expctusi INT(1) UNSIGNED, \
 stoasp_scmssch SMALLINT(1) UNSIGNED, \
 stoasp_calflag1 TINYINT(1) UNSIGNED, \
 stoasp_rdevdran TINYINT(1) UNSIGNED, \
 stoasp_expcont BINARY(80), \
 stoasp_expdevst INT(1) UNSIGNED, \
 stoasp_expmload INT(1) UNSIGNED, \
 stoasp_cpvlokat INT(1) UNSIGNED, \
 stoasp_cpvalocd INT(1) UNSIGNED, \
 stoasp_scgssch INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";


const char *query_create_d3r5=
 "CREATE TABLE IF NOT EXISTS d3r5 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stoshs_sdffn CHAR(8), \
 stoshs_sdfft CHAR(8), \
 stoshs_sdfcltim INT(1) UNSIGNED, \
 stoshs_sdfidnum SMALLINT(1) SIGNED, \
 stoshs_sdfclass CHAR(1), \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d3r6=
 "CREATE TABLE IF NOT EXISTS d3r6 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stoshp_sdffn CHAR(8), \
 stoshp_sdfft CHAR(8), \
 stoshp_sdfcltim INT(1) UNSIGNED, \
 stoshp_sdfidnum SMALLINT(1) SIGNED, \
 stoshp_sdfclass CHAR(1), \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d3r7=
 "CREATE TABLE IF NOT EXISTS d3r7 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stoatc_cpvolser CHAR(6), \
 stoatc_calflags TINYINT(1) UNSIGNED, \
 stoatc_caltype CHAR(4), \
 stoatc_calcylno INT(1) SIGNED, \
 stoatc_calstart INT(1) SIGNED, \
 stoatc_rdcpcyl INT(1) SIGNED, \
 stoatc_rdevsid INT(1) UNSIGNED, \
 stoatc_rdevdev SMALLINT(1) UNSIGNED, \
 PRIMARY KEY (id), \
 INDEX (id), \
 UNIQUE INDEX (time, stoatc_cpvolser)) ENGINE=ARCHIVE";

const char *query_create_d3r8=
 "CREATE TABLE IF NOT EXISTS d3r8 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stobpg_pgdbr_tbl BINARY(80), \
 stobpg_pgdbm_tbl BINARY(80), \
 stobpg_pgdbs_tbl BINARY(80), \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d3r9=
 "CREATE TABLE IF NOT EXISTS d3r9 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stoxsg_xstmigs INT(1) UNSIGNED, \
 stoxsg_xstblkdm INT(1) UNSIGNED, \
 stoxsg_xstsumag BINARY(8), \
 stoxsg_xstblkcy INT(1) UNSIGNED, \
 stoxsg_xstblksh INT(1) UNSIGNED, \
 stoxsg_xstblksy INT(1) UNSIGNED, \
 stoxsg_xstlothr INT(1) UNSIGNED, \
 stoxsg_xstcycls INT(1) UNSIGNED, \
 stoxsg_xstcpdal INT(1) UNSIGNED, \
 stoxsg_xstguest INT(1) UNSIGNED, \
 stoxsg_xstnoio BINARY(8), \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d3r10=
 "CREATE TABLE IF NOT EXISTS d3r10 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stoxsu_vmduser CHAR(8), \
 stoxsu_calxstor INT(1) UNSIGNED, \
 stoxsu_calorgin INT(1) UNSIGNED, \
 stoxsu_calxslim INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d3r11=
 "CREATE TABLE IF NOT EXISTS d3r11 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stoass_cpvolser CHAR(6), \
 stoass_rdevsid INT(1) UNSIGNED, \
 stoass_expctsrd INT(1) UNSIGNED, \
 stoass_expctswr INT(1) UNSIGNED, \
 stoass_expctprd INT(1) UNSIGNED, \
 stoass_expctpwr INT(1) UNSIGNED, \
 stoass_expcurqc INT(1) UNSIGNED, \
 stoass_expctacp INT(1) UNSIGNED, \
 stoass_expctusi INT(1) UNSIGNED, \
 stoass_scmssch SMALLINT(1) UNSIGNED, \
 stoass_scgssch INT(1) UNSIGNED, \
 stoass_rdevdev SMALLINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d3r12=
 "CREATE TABLE IF NOT EXISTS d3r12 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stoasc_ascusrid CHAR(8), \
 stoasc_ascname CHAR(24), \
 stoasc_ascssize INT(1) SIGNED, \
 stoasc_ascdefsz BINARY(8), \
 stoasc_caldefhi BINARY(4), \
 stoasc_caldeflo BINARY(4), \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d3r13=
 "CREATE TABLE IF NOT EXISTS d3r13 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stoasd_ascusrid CHAR(8), \
 stoasd_ascname CHAR(24), \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d3r14=
 "CREATE TABLE IF NOT EXISTS d3r14 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stoasi_ascusrid CHAR(8), \
 stoasi_ascname CHAR(24), \
 stoasi_calstate TINYINT(1) UNSIGNED, \
 stoasi_ascctspi INT(1) UNSIGNED, \
 stoasi_ascctprs INT(1) UNSIGNED, \
 stoasi_asccspst INT(1) UNSIGNED, \
 stoasi_asccspgr INT(1) UNSIGNED, \
 stoasi_asccspgw INT(1) UNSIGNED, \
 stoasi_asccsxrd INT(1) UNSIGNED, \
 stoasi_asccsxwt INT(1) UNSIGNED, \
 stoasi_asccsmig INT(1) UNSIGNED, \
 stoasi_ascctplk INT(1) UNSIGNED, \
 stoasi_ascctpgs INT(1) UNSIGNED, \
 stoasi_ascctxbk INT(1) UNSIGNED, \
 stoasi_ascssize INT(1) UNSIGNED, \
 stoasi_ascdefsz CHAR(8), \
 stoasi_caldefhi CHAR(4), \
 stoasi_caldeflo CHAR(4), \
 stoasi_ascmvb2g INT(1) UNSIGNED, \
 stoasi_ascctprg INT(1) UNSIGNED, \
 stoasi_aschllc INT(1) UNSIGNED, \
 stoasi_aschlrc INT(1) UNSIGNED, \
 stoasi_ascctplka CHAR(8), \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d3r15=
 "CREATE TABLE IF NOT EXISTS d3r15 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stoshl_sdffn CHAR(8), \
 stoshl_sdfft CHAR(8), \
 stoshl_sdfcltim INT(1) UNSIGNED, \
 stoshl_sdfidnum SMALLINT(1) SIGNED, \
 stoshl_sdfclass CHAR(1), \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d3r16=
 "CREATE TABLE IF NOT EXISTS d3r16 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stoshd_sdffn CHAR(8), \
 stoshd_sdfft CHAR(8), \
 stoshd_sdfcltim INT(1) UNSIGNED, \
 stoshd_sdfidnum SMALLINT(1) SIGNED, \
 stoshd_sdfclass CHAR(1), \
 stoshd_ascctprs INT(1) UNSIGNED, \
 stoshd_sntstrct INT(1) UNSIGNED, \
 stoshd_sntndtct INT(1) UNSIGNED, \
 stoshd_asccspst INT(1) UNSIGNED, \
 stoshd_ascptrsh INT(1) UNSIGNED, \
 stoshd_asccspgr INT(1) UNSIGNED, \
 stoshd_asccspgw INT(1) UNSIGNED, \
 stoshd_asccsxrd INT(1) UNSIGNED, \
 stoshd_asccsxwt INT(1) UNSIGNED, \
 stoshd_asccsmig INT(1) UNSIGNED, \
 stoshd_ascctpgs INT(1) UNSIGNED, \
 stoshd_ascctprg INT(1) UNSIGNED, \
 stoshd_aschllc INT(1) UNSIGNED, \
 stoshd_aschlrc INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d3r17=
 "CREATE TABLE IF NOT EXISTS d3r17 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stovdk_mdiouser CHAR(8), \
 stovdk_qdisname CHAR(24), \
 stovdk_mdiovdev SMALLINT(1) UNSIGNED, \
 stovdk_calflag TINYINT(1) UNSIGNED, \
 stovdk_mdilinks INT(1) UNSIGNED, \
 stovdk_calsize INT(1) UNSIGNED, \
 stovdk_qdiiocnt INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d3r18=
 "CREATE TABLE IF NOT EXISTS d3r18 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stoscs_poolname CHAR(8), \
 stoscs_frxroot INT(1) UNSIGNED, \
 stoscs_frxplen INT(1) UNSIGNED, \
 stoscs_malloc INT(1) UNSIGNED, \
 stoscs_mallocf INT(1) UNSIGNED, \
 stoscs_frees INT(1) UNSIGNED, \
 stoscs_freef INT(1) UNSIGNED, \
 stoscs_current INT(1) UNSIGNED, \
 stoscs_maxalloc INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d3r19=
 "CREATE TABLE IF NOT EXISTS d3r19 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stosxg_rsasxuot INT(1) UNSIGNED, \
 stosxg_rsasxctg INT(1) UNSIGNED, \
 stosxg_rsasxcpl INT(1) UNSIGNED, \
 stosxg_rsasxpct INT(1) UNSIGNED, \
 stosxg_rsasxdct INT(1) UNSIGNED, \
 stosxg_rsasxdca INT(1) UNSIGNED, \
 stosxg_rsasxdpa INT(1) UNSIGNED, \
 stosxg_rsasxdpb INT(1) UNSIGNED, \
 stosxg_rsasxdfa INT(1) UNSIGNED, \
 stosxg_rsasxdfb INT(1) UNSIGNED, \
 stosxg_rsasxrda INT(1) UNSIGNED, \
 stosxg_rsasxrdc INT(1) UNSIGNED, \
 stosxg_rsasxamx INT(1) UNSIGNED, \
 stosxg_rsasxbmx INT(1) UNSIGNED, \
 stosxg_rsasxqmn INT(1) UNSIGNED, \
 stosxg_rsasxqra INT(1) UNSIGNED, \
 stosxg_rsasxrpm INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d3r20=
 "CREATE TABLE IF NOT EXISTS d3r20 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 stosxp_pfxcpuad SMALLINT(1) UNSIGNED, \
 stosxp_plssutkc INT(1) UNSIGNED, \
 stosxp_plssurtc INT(1) UNSIGNED, \
 stosxp_plssupuc INT(1) UNSIGNED, \
 stosxp_plssuqmt INT(1) UNSIGNED, \
 stosxp_plssatkc INT(1) UNSIGNED, \
 stosxp_plssartc INT(1) UNSIGNED, \
 stosxp_plssapuc INT(1) UNSIGNED, \
 stosxp_plssaqmt INT(1) UNSIGNED, \
 stosxp_plssbtkc INT(1) UNSIGNED, \
 stosxp_plssbrtc INT(1) UNSIGNED, \
 stosxp_plssbpuc INT(1) UNSIGNED, \
 stosxp_plssbqmt INT(1) UNSIGNED, \
 stosxp_plssxals INT(1) UNSIGNED, \
 stosxp_plssxadc INT(1) UNSIGNED, \
 stosxp_plssxasc INT(1) UNSIGNED, \
 stosxp_plsspndp INT(1) UNSIGNED, \
 stosxp_plsspndf INT(1) UNSIGNED, \
 stosxp_plsspgpd INT(1) UNSIGNED, \
 stosxp_plsspgfd INT(1) UNSIGNED, \
 stosxp_plsspgbd INT(1) UNSIGNED, \
 stosxp_plsspdqc INT(1) UNSIGNED, \
 stosxp_plssxipc INT(1) UNSIGNED, \
 stosxp_plssxnst INT(1) UNSIGNED, \
 stosxp_plssxafc INT(1) UNSIGNED, \
 stosxp_plssxcsp INT(1) UNSIGNED, \
 stosxp_plssxald INT(1) UNSIGNED, \
 stosxp_pfxcputy TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";


//DOMAIN-4's TABLE
const char *query_create_d4r5=
 "CREATE TABLE IF NOT EXISTS d4r5 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 usedfc_vmduser CHAR(8), \
 usedfc_vmdcpuad SMALLINT(1) UNSIGNED, \
 usedfc_vmdputyp TINYINT(1) UNSIGNED, \
 usedfc_vmdcfgem TINYINT(1) UNSIGNED, \
 usedfc_vmdpust TINYINT(1) UNSIGNED, \
 usedfc_oldputyp TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d4r6=
 "CREATE TABLE IF NOT EXISTS d4r6 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 usedtc_vmduser CHAR(8), \
 usedtc_vmdcpuad SMALLINT(1) UNSIGNED, \
 usedtc_vmdputyp TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d4r7=
 "CREATE TABLE IF NOT EXISTS d4r7 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 userdc_vmduser CHAR(8), \
 userdc_vmdcpuad SMALLINT(1) UNSIGNED, \
 userdc_newcpuad SMALLINT(1) UNSIGNED, \
 userdc_vmdputyp TINYINT(1) UNSIGNED, \
 userdc_newputyp TINYINT(1) UNSIGNED, \
 userdc_vmdcfgem TINYINT(1) UNSIGNED, \
 userdc_vmdpust TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";


/*
const char *query_create_d4r9 =
 "CREATE TABLE IF NOT EXISTS d4r9 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP UNIQUE, \

 useate_vmduser CHAR(8), \
 useate_vmdcpuad SMALLINT(1) UNSIGNED, \
 useate_vmdmode TINYINT(1) UNSIGNED, \
 useate_calmode TINYINT(1) UNSIGNED, \
 useate_vmdttime CHAR(8), \ //--time
 useate_vmdvtime CHAR(8), \ //--time
 useate_vmdctpvr INT(1) UNSIGNED, \
 useate_vmdctpvl INT(1) UNSIGNED, \
 useate_vmdwsspr INT(1) UNSIGNED, \
 useate_vmdctxbk INT(1) UNSIGNED, \
 useate_vmdctflt INT(1) UNSIGNED, \
 useate_vmdctorf INT(1) UNSIGNED, \
 useate_calctpgs INT(1) UNSIGNED, \
 useate_vmdctpwt INT(1) UNSIGNED, \
 useate_calcppgr INT(1) UNSIGNED, \
 useate_calcppgw INT(1) UNSIGNED, \
 useate_vmdctspr INT(1) UNSIGNED, \
 useate_vmdctspw INT(1) UNSIGNED, \
 useate_vmdpgspl INT(1) UNSIGNED, \
 useate_vmdvcsct INT(1) UNSIGNED, \
 useate_vmdvdsct INT(1) UNSIGNED, \
 useate_vmdvusct INT(1) UNSIGNED, \
 useate_vmdvtsct INT(1) UNSIGNED, \
 useate_vmdvosct INT(1) UNSIGNED, \
 useate_calcppst INT(1) UNSIGNED, \
 useate_vmdisevm INT(1) UNSIGNED, \
 useate_vmdistvm INT(1) UNSIGNED, \
 useate_vmdisuvm INT(1) UNSIGNED, \
 useate_vmdvsevm INT(1) UNSIGNED, \
 useate_vmdvstvm INT(1) UNSIGNED, \
 useate_vmdvsuvm INT(1) UNSIGNED, \
 useate_vmdx98ct INT(1) UNSIGNED, \
 useate_calcpmig INT(1) UNSIGNED, \
 useate_calcpxwt INT(1) UNSIGNED, \
 useate_calcpxrd INT(1) UNSIGNED, \
 useate_calflag1 TINYINT(1) UNSIGNED, \
 useate_vmdstype TINYINT(1) UNSIGNED, \
 useate_calsharf TINYINT(1) UNSIGNED, \
 useate_vmdblkct INT(1) UNSIGNED, \
 useate_vmdmdcia INT(1) UNSIGNED, \
 useate_vmdcopct INT(1) UNSIGNED, \
 useate_vmdctiso INT(1) UNSIGNED, \
 useate_vmdrelsh INT(1) UNSIGNED, \
 useate_vmdabssh INT(1) UNSIGNED, \
 useate_vmdssize INT(1) UNSIGNED, \
 useate_vmdmxrvp INT(1) UNSIGNED, \
 useate_vmdactno CHAR(8), \
 useate_vmdgrpn CHAR(8), \
 useate_caltodon CHAR(8), \  //--time
 useate_vmdvdisk INT(1) UNSIGNED, \
 useate_vmdmxshr INT(1) UNSIGNED, \
 useate_ascdefsz BINARY(8), \
 useate_caldefhi BINARY(4), \
 useate_caldeflo BINARY(4), \
 useate_vmdctpvg INT(1) UNSIGNED, \
 useate_vmdmvb2g INT(1) UNSIGNED, \
 useate_vebalert INT(1) UNSIGNED, \
 useate_vebtvsct INT(1) UNSIGNED, \
 useate_vebsvsct INT(1) UNSIGNED, \
 useate_vebtpiai INT(1) UNSIGNED, \
 useate_vebvirai INT(1) UNSIGNED, \
 useate_vebhdwai INT(1) UNSIGNED, \
 useate_vmdctpvla CHAR(8), \
 useate_vmdctshl INT(1) UNSIGNED, \
 useate_vmdctshla BINARY(8), \
 useate_vmdputyp TINYINT(1) UNSIGNED, \
 useate_vmdcfgem TINYINT(1) UNSIGNED, \
 useate_vmdpust  TINYINT(1) UNSIGNED, \
 useate_vmdvtmp BINARY(8), \
 useate_vmdttmp BINARY(8), \
 useate_vmdvtms BINARY(8), \
 useate_vmdttms BINARY(8), \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";
*/
const char *query_create_d4r10 =
 "CREATE TABLE IF NOT EXISTS d4r10 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP UNIQUE, \
 useite_vmduser CHAR(8), \
 useite_vmdcpuad SMALLINT(1) UNSIGNED, \
 useite_vmdslcnt SMALLINT(1) SIGNED, \
 useite_vmdsvmfx INT(1) UNSIGNED, \
 useite_vmdsvmid CHAR(8), \
 useite_vmdsvmwt TINYINT(1) UNSIGNED, \
 useite_vmdsvmw2 TINYINT(1) UNSIGNED, \
 useite_vmdsvmcm TINYINT(1) UNSIGNED, \
 useite_calflag1 TINYINT(1) UNSIGNED, \
 useite_hfquct INT(1) UNSIGNED, \
 useite_hfdisp0 INT(1) UNSIGNED, \
 useite_hfdisp1 INT(1) UNSIGNED, \
 useite_hfdisp2 INT(1) UNSIGNED, \
 useite_hfdisp3 INT(1) UNSIGNED, \
 useite_hfelig0 INT(1) UNSIGNED, \
 useite_hfelig1 INT(1) UNSIGNED, \
 useite_hfelig2 INT(1) UNSIGNED, \
 useite_hfelig3 INT(1) UNSIGNED, \
 useite_hfstct INT(1) UNSIGNED, \
 useite_hftidl INT(1) UNSIGNEd, \
 useite_hftsvm INT(1) UNSIGNED, \
 useite_hfiowt INT(1) UNSIGNED, \
 useite_hfcfwt INT(1) UNSIGNED, \
 useite_hfsimwt INT(1) UNSIGNED, \
 useite_hfwtpag INT(1) UNSIGNED, \
 useite_hfcpuwt INT(1) UNSIGNED, \
 useite_hfcpurn INT(1) UNSIGNED, \
 useite_hfesvm INT(1) UNSIGNED, \
 useite_hfload INT(1) UNSIGNED, \
 useite_hfdorm INT(1) UNSIGNED, \
 useite_hfdsvm INT(1) SIGNED, \
 useite_hfothr INT(1) UNSIGNED, \
 useite_vmdcntid SMALLINT(1) UNSIGNED, \
 useite_vmdctidl SMALLINT(1) UNSIGNED, \
 useite_vmddfrwk INT(1) UNSIGNED, \
 useite_vmdstate TINYINT(1) UNSIGNED, \
 useite_calostat TINYINT(1) UNSIGNED, \
 useite_calrstat TINYINT(1) UNSIGNED, \
 useite_vmdcprmd_q0 SMALLINT(1) UNSIGNED, \
 useite_vmdcprmd_q1 SMALLINT(1) UNSIGNED, \
 useite_vmdcprmd_q2 SMALLINT(1) UNSIGNED, \
 useite_vmdcprmd_q3 SMALLINT(1) UNSIGNED, \
 useite_vmdcwsgd_q0 SMALLINT(1) UNSIGNED, \
 useite_vmdcwsgd_q1 SMALLINT(1) UNSIGNED, \
 useite_vmdcwsgd_q2 SMALLINT(1) UNSIGNED, \
 useite_vmdcwsgd_q3 SMALLINT(1) UNSIGNED, \
 useite_vmdcetsd_q0 SMALLINT(1) UNSIGNED, \
 useite_vmdcetsd_q1 SMALLINT(1) UNSIGNED, \
 useite_vmdcetsd_q2 SMALLINT(1) UNSIGNED, \
 useite_vmdcetsd_q3 SMALLINT(1) UNSIGNED, \
 useite_vmdcidld_q0 SMALLINT(1) UNSIGNED, \
 useite_vmdcidld_q1 SMALLINT(1) UNSIGNED, \
 useite_vmdcidld_q2 SMALLINT(1) UNSIGNED, \
 useite_vmdcidld_q3 SMALLINT(1) UNSIGNED, \
 useite_hfioact INT(1) UNSIGNED, \
 useite_hfllist INT(1) UNSIGNED, \
 useite_hfpgact INT(1) UNSIGNED, \
 useite_vmdputyp TINYINT(1) UNSIGNED, \
 useite_vmdcfgem TINYINT(1) UNSIGNED, \
 useite_vmdpust TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

//DOMAIN-5's TABLE
const char *query_create_d5r1=
 "CREATE TABLE IF NOT EXISTS d5r1 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 prcvon_pfxcpuad SMALLINT(1) UNSIGNED, \
 prcvon_pfxidmdl CHAR(2), \
 prcvon_pfxidser CHAR(3), \
 prcvon_pfxidver TINYINT(1) UNSIGNED, \
 prcvon_pfxcputy TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d5r2=
 "CREATE TABLE IF NOT EXISTS d5r2 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 prcvof_pfxcpuad SMALLINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d5r3=
 "CREATE TABLE IF NOT EXISTS d5r3 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 prcprp_pfxcpuad SMALLINT(1) UNSIGNED, \
 prcprp_pfxdspcs INT(1) UNSIGNED, \
 prcprp_plsdspcm INT(1) UNSIGNED, \
 prcprp_dsvmaxus INT(1) UNSIGNED, \
 prcprp_hfcount INT(1) UNSIGNED, \
 prcprp_hfuserz INT(1) UNSIGNED, \
 prcprp_hfuserc INT(1) UNSIGNED, \
 prcprp_caluded CHAR(8), \
 prcprp_pfxtype TINYINT(1) UNSIGNED, \
 prcprp_hfuserm INT(1) UNSIGNED, \
 prcprp_plsstlct BLOB(256), \
 prcprp_pfxcputy TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d5r6=
 "CREATE TABLE IF NOT EXISTS d5r6 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 prccfn_pfxcpuad SMALLINT(1) UNSIGNED, \
 prccfn_pcccsu TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d5r7=
 "CREATE TABLE IF NOT EXISTS d5r7 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 prccff_pfxcpuad SMALLINT(1) UNSIGNED, \
 prccff_pcccsu TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d5r8=
 "CREATE TABLE IF NOT EXISTS d5r8 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 prciop_csciopid INT(1) UNSIGNED, \
 prciop_cscvblbc INT(1) UNSIGNED, \
 prciop_cscvblic INT(1) UNSIGNED, \
 prciop_cscvblsc INT(1) UNSIGNED, \
 prciop_cscvblpi INT(1) UNSIGNED, \
 prciop_cscvblcb INT(1) UNSIGNED, \
 prciop_cscvblsb INT(1) UNSIGNED, \
 prciop_cscvblub INT(1) UNSIGNED, \
 prciop_cscvbldb INT(1) UNSIGNED, \
 prciop_cscmdbc BINARY(8), \
 prciop_cscmdic BINARY(8), \
 prciop_cscmdsc BINARY(8), \
 prciop_cscmdpi BINARY(8), \
 prciop_cscmdcb BINARY(8), \
 prciop_cscmdsb BINARY(8), \
 prciop_cscmdub BINARY(8), \
 prciop_cscmddb BINARY(8), \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d5r9=
 "CREATE TABLE IF NOT EXISTS d5r9 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 prcapc_cryvserv BINARY(8), \
 prcapc_cryrserv BINARY(8), \
 prcapc_crynownq BINARY(8), \
 prcapc_crynovnq BINARY(8), \
 prcapc_crynoxvn BINARY(8), \
 prcapc_crynoxrn BINARY(8), \
 prcapc_crynofnq BINARY(8), \
 prcapc_crynofdq BINARY(8), \
 prcapc_crynovpr BINARY(8), \
 prcapc_crynovpc BINARY(8), \
 prcapc_crynorpr BINARY(8), \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d5r11=
 "CREATE TABLE IF NOT EXISTS d5r11 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 prcins_pfxcpuad INT(1) UNSIGNED, \
 prcins_plskeyik INT(1) UNSIGNED, \
 prcins_plskeysk INT(1) UNSIGNED, \
 prcins_plsprvsv INT(1) UNSIGNED, \
 prcins_plsprvms INT(1) UNSIGNED, \
 prcins_plsprvlp INT(1) UNSIGNED, \
 prcins_plsprvmn INT(1) UNSIGNED, \
 prcins_plsprvmo INT(1) UNSIGNED, \
 prcins_plsprvgp INT(1) UNSIGNED, \
 prcins_plsprvtc INT(1) UNSIGNED, \
 prcins_plsprvlc INT(1) UNSIGNED, \
 prcins_plsptff INT(1) UNSIGNED, \
 prcins_plssckpf INT(1) UNSIGNED, \
 prcins_plsbiscp INT(1) UNSIGNED, \
 prcins_plsbiste INT(1) UNSIGNED, \
 prcins_plsbispb INT(1) UNSIGNED, \
 prcins_plsbisxe INT(1) UNSIGNED, \
 prcins_plsbisxs INT(1) UNSIGNED, \
 prcins_plsbisas INT(1) UNSIGNED, \
 prcins_plskeyrr INT(1) UNSIGNED, \
 prcins_plsbissi INT(1) UNSIGNED, \
 prcins_plspcvsc INT(1) UNSIGNED, \
 prcins_plsvptnv INT(1) UNSIGNED, \
 prcins_plskeyie INT(1) UNSIGNED, \
 prcins_plskeyre INT(1) UNSIGNED, \
 prcins_plskeyse INT(1) UNSIGNED, \
 prcins_plsbisbt INT(1) UNSIGNED, \
 prcins_plsxpgin INT(1) UNSIGNED, \
 prcins_plsxpgou INT(1) UNSIGNED, \
 prcins_plsviesb INT(1) UNSIGNED, \
 prcins_plsxpg5a INT(1) UNSIGNED, \
 prcins_plsbisst INT(1) UNSIGNED, \
 prcins_plsstfle INT(1) UNSIGNED, \
 prcins_pls0stfl INT(1) UNSIGNED, \
 prcins_plslpswe INT(1) UNSIGNED, \
 prcins_plsbisiu INT(1) UNSIGNED, \
 prcins_pls0epsw INT(1) UNSIGNED, \
 prcins_plsvidte INT(1) UNSIGNED, \
 prcins_pls0esea INT(1) UNSIGNED, \
 prcins_plsessa INT(1) UNSIGNED, \
 prcins_plsprvtp INT(1) UNSIGNED, \
 prcins_plsprvsg INT(1) UNSIGNED, \
 prcins_plsprvlg INT(1) UNSIGNED, \
 prcins_plsprvvn INT(1) UNSIGNED, \
 prcins_plstccc INT(1) UNSIGNED, \
 prcins_plssschc INT(1) UNSIGNED, \
 prcins_plsrschc INT(1) UNSIGNED, \
 prcins_plssioct INT(1) UNSIGNED, \
 prcins_plssiofc INT(1) UNSIGNED, \
 prcins_plsctss INT(1) UNSIGNED, \
 prcins_plsctrs INT(1) UNSIGNED, \
 prcins_plsctcs INT(1) UNSIGNED, \
 prcins_plscths INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d5r12=
 "CREATE TABLE IF NOT EXISTS d5r12 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 prcdia_pfxcpuad INT(1) UNSIGNED, \
 prcdia_plsdgx00 INT(1) UNSIGNED, \
 prcdia_plsdgx04 INT(1) UNSIGNED, \
 prcdia_plsdgx08 INT(1) UNSIGNED, \
 prcdia_plsdgx0c INT(1) UNSIGNED, \
 prcdia_plsdgx10 INT(1) UNSIGNED, \
 prcdia_plsdgx14 INT(1) UNSIGNED, \
 prcdia_plsdgx18 INT(1) UNSIGNED, \
 prcdia_plsdgx1c INT(1) UNSIGNED, \
 prcdia_plsdgx20 INT(1) UNSIGNED, \
 prcdia_plsdgx24 INT(1) UNSIGNED, \
 prcdia_plsdgx28 INT(1) UNSIGNED, \
 prcdia_plsdgx2c INT(1) UNSIGNED, \
 prcdia_plsdgx30 INT(1) UNSIGNED, \
 prcdia_plsdgx34 INT(1) UNSIGNED, \
 prcdia_plsdgx38 INT(1) UNSIGNED, \
 prcdia_plsdgx3c INT(1) UNSIGNED, \
 prcdia_plsdgx40 INT(1) UNSIGNED, \
 prcdia_plsdgx44 INT(1) UNSIGNED, \
 prcdia_plsdgx48 INT(1) UNSIGNED, \
 prcdia_plsdgx4c INT(1) UNSIGNED, \
 prcdia_plsdgx50 INT(1) UNSIGNED, \
 prcdia_plsdgx54 INT(1) UNSIGNED, \
 prcdia_plsdgx58 INT(1) UNSIGNED, \
 prcdia_plsdgx5c INT(1) UNSIGNED, \
 prcdia_plsdgx60 INT(1) UNSIGNED, \
 prcdia_plsdgx64 INT(1) UNSIGNED, \
 prcdia_plsdgx68 INT(1) UNSIGNED, \
 prcdia_plsdgx6c INT(1) UNSIGNED, \
 prcdia_plsdgx70 INT(1) UNSIGNED, \
 prcdia_plsdgx74 INT(1) UNSIGNED, \
 prcdia_plsdgx78 INT(1) UNSIGNED, \
 prcdia_plsdgx7c INT(1) UNSIGNED, \
 prcdia_plsdgx80 INT(1) UNSIGNED, \
 prcdia_plsdgx84 INT(1) UNSIGNED, \
 prcdia_plsdgx88 INT(1) UNSIGNED, \
 prcdia_plsdgx8c INT(1) UNSIGNED, \
 prcdia_plsdgx90 INT(1) UNSIGNED, \
 prcdia_plsdgx94 INT(1) UNSIGNED, \
 prcdia_plsdgx98 INT(1) UNSIGNED, \
 prcdia_plsdgx9c INT(1) UNSIGNED, \
 prcdia_plsdgxa0 INT(1) UNSIGNED, \
 prcdia_plsdgxa4 INT(1) UNSIGNED, \
 prcdia_plsdgxa8 INT(1) UNSIGNED, \
 prcdia_plsdgxac INT(1) UNSIGNED, \
 prcdia_plsdgxb0 INT(1) UNSIGNED, \
 prcdia_plsdgxb4 INT(1) UNSIGNED, \
 prcdia_plsdgxb8 INT(1) UNSIGNED, \
 prcdia_plsdgxbc INT(1) UNSIGNED, \
 prcdia_plsdgxc0 INT(1) UNSIGNED, \
 prcdia_plsdgxc4 INT(1) UNSIGNED, \
 prcdia_plsdgxc8 INT(1) UNSIGNED, \
 prcdia_plsdgxcc INT(1) UNSIGNED, \
 prcdia_plsdgxd0 INT(1) UNSIGNED, \
 prcdia_plsdgxd4 INT(1) UNSIGNED, \
 prcdia_plsdgxd8 INT(1) UNSIGNED, \
 prcdia_plsdgxdc INT(1) UNSIGNED, \
 prcdia_plsdgxe0 INT(1) UNSIGNED, \
 prcdia_plsdgxe4 INT(1) UNSIGNED, \
 prcdia_plsdgxe8 INT(1) UNSIGNED, \
 prcdia_plsdgxec INT(1) UNSIGNED, \
 prcdia_plsdgxf0 INT(1) UNSIGNED, \
 prcdia_plsdgxf4 INT(1) UNSIGNED, \
 prcdia_plsdgxf8 INT(1) UNSIGNED, \
 prcdia_plsdgxfc INT(1) UNSIGNED, \
 prcdia_plsdguct INT(1) UNSIGNED, \
 prcdia_plsdg200 INT(1) UNSIGNED, \
 prcdia_plsdg204 INT(1) UNSIGNED, \
 prcdia_plsdg208 INT(1) UNSIGNED, \
 prcdia_plsdg20c INT(1) UNSIGNED, \
 prcdia_plsdg210 INT(1) UNSIGNED, \
 prcdia_plsdg214 INT(1) UNSIGNED, \
 prcdia_plsdg218 INT(1) UNSIGNED, \
 prcdia_plsdg21c INT(1) UNSIGNED, \
 prcdia_plsdg220 INT(1) UNSIGNED, \
 prcdia_plsdg224 INT(1) UNSIGNED, \
 prcdia_plsdg228 INT(1) UNSIGNED, \
 prcdia_plsdg22c INT(1) UNSIGNED, \
 prcdia_plsdg230 INT(1) UNSIGNED, \
 prcdia_plsdg234 INT(1) UNSIGNED, \
 prcdia_plsdg238 INT(1) UNSIGNED, \
 prcdia_plsdg23c INT(1) UNSIGNED, \
 prcdia_plsdg240 INT(1) UNSIGNED, \
 prcdia_plsdg244 INT(1) UNSIGNED, \
 prcdia_plsdg248 INT(1) UNSIGNED, \
 prcdia_plsdg24c INT(1) UNSIGNED, \
 prcdia_plsdg250 INT(1) UNSIGNED, \
 prcdia_plsdg254 INT(1) UNSIGNED, \
 prcdia_plsdg258 INT(1) UNSIGNED, \
 prcdia_plsdg25c INT(1) UNSIGNED, \
 prcdia_plsdg260 INT(1) UNSIGNED, \
 prcdia_plsdg264 INT(1) UNSIGNED, \
 prcdia_plsdg268 INT(1) UNSIGNED, \
 prcdia_plsdg26c INT(1) UNSIGNED, \
 prcdia_plsdg270 INT(1) UNSIGNED, \
 prcdia_plsdg274 INT(1) UNSIGNED, \
 prcdia_plsdg278 INT(1) UNSIGNED, \
 prcdia_plsdg27c INT(1) UNSIGNED, \
 prcdia_plsdg280 INT(1) UNSIGNED, \
 prcdia_plsdg284 INT(1) UNSIGNED, \
 prcdia_plsdg288 INT(1) UNSIGNED, \
 prcdia_plsdg28c INT(1) UNSIGNED, \
 prcdia_plsdg290 INT(1) UNSIGNED, \
 prcdia_plsdg294 INT(1) UNSIGNED, \
 prcdia_plsdg298 INT(1) UNSIGNED, \
 prcdia_plsdg29c INT(1) UNSIGNED, \
 prcdia_plsdg2a0 INT(1) UNSIGNED, \
 prcdia_plsdg2a4 INT(1) UNSIGNED, \
 prcdia_plsdg2a8 INT(1) UNSIGNED, \
 prcdia_plsdg2ac INT(1) UNSIGNED, \
 prcdia_plsdg2b0 INT(1) UNSIGNED, \
 prcdia_plsdg2b4 INT(1) UNSIGNED, \
 prcdia_plsdg2b8 INT(1) UNSIGNED, \
 prcdia_plsdg2bc INT(1) UNSIGNED, \
 prcdia_plsdg2c0 INT(1) UNSIGNED, \
 prcdia_plsdg2c4 INT(1) UNSIGNED, \
 prcdia_plsdg2c8 INT(1) UNSIGNED, \
 prcdia_plsdg2cc INT(1) UNSIGNED, \
 prcdia_plsdg2d0 INT(1) UNSIGNED, \
 prcdia_plsdg2d4 INT(1) UNSIGNED, \
 prcdia_plsdg2d8 INT(1) UNSIGNED, \
 prcdia_plsdg2dc INT(1) UNSIGNED, \
 prcdia_plsdg2e0 INT(1) UNSIGNED, \
 prcdia_plsdg2e4 INT(1) UNSIGNED, \
 prcdia_plsdg2e8 INT(1) UNSIGNED, \
 prcdia_plsdg2ec INT(1) UNSIGNED, \
 prcdia_plsdg2f0 INT(1) UNSIGNED, \
 prcdia_plsdg2f4 INT(1) UNSIGNED, \
 prcdia_plsdg2f8 INT(1) UNSIGNED, \
 prcdia_plsdg2fc INT(1) UNSIGNED, \
 prcdia_plsdg300 INT(1) UNSIGNED, \
 prcdia_plsdg304 INT(1) UNSIGNED, \
 prcdia_plsdg308 INT(1) UNSIGNED, \
 prcdia_plsdg30c INT(1) UNSIGNED, \
 prcdia_plsdg310 INT(1) UNSIGNED, \
 prcdia_plsdg314 INT(1) UNSIGNED, \
 prcdia_plsdg318 INT(1) UNSIGNED, \
 prcdia_plsdg31c INT(1) UNSIGNED, \
 prcdia_plsdg320 INT(1) UNSIGNED, \
 prcdia_plsdg324 INT(1) UNSIGNED, \
 prcdia_plsdg328 INT(1) UNSIGNED, \
 prcdia_plsdg32c INT(1) UNSIGNED, \
 prcdia_plsdg330 INT(1) UNSIGNED, \
 prcdia_plsdg334 INT(1) UNSIGNED, \
 prcdia_plsdg338 INT(1) UNSIGNED, \
 prcdia_plsdg33c INT(1) UNSIGNED, \
 prcdia_plsdg340 INT(1) UNSIGNED, \
 prcdia_plsdg344 INT(1) UNSIGNED, \
 prcdia_plsdg348 INT(1) UNSIGNED, \
 prcdia_plsdg34c INT(1) UNSIGNED, \
 prcdia_plsdg350 INT(1) UNSIGNED, \
 prcdia_plsdg354 INT(1) UNSIGNED, \
 prcdia_plsdg358 INT(1) UNSIGNED, \
 prcdia_plsdg35c INT(1) UNSIGNED, \
 prcdia_plsdg360 INT(1) UNSIGNED, \
 prcdia_plsdg364 INT(1) UNSIGNED, \
 prcdia_plsdg368 INT(1) UNSIGNED, \
 prcdia_plsdg36c INT(1) UNSIGNED, \
 prcdia_plsdg370 INT(1) UNSIGNED, \
 prcdia_plsdg374 INT(1) UNSIGNED, \
 prcdia_plsdg378 INT(1) UNSIGNED, \
 prcdia_plsdg37c INT(1) UNSIGNED, \
 prcdia_plsdg380 INT(1) UNSIGNED, \
 prcdia_plsdg384 INT(1) UNSIGNED, \
 prcdia_plsdg388 INT(1) UNSIGNED, \
 prcdia_plsdg38c INT(1) UNSIGNED, \
 prcdia_plsdg390 INT(1) UNSIGNED, \
 prcdia_plsdg394 INT(1) UNSIGNED, \
 prcdia_plsdg398 INT(1) UNSIGNED, \
 prcdia_plsdg39c INT(1) UNSIGNED, \
 prcdia_plsdg3a0 INT(1) UNSIGNED, \
 prcdia_plsdg3a4 INT(1) UNSIGNED, \
 prcdia_plsdg3a8 INT(1) UNSIGNED, \
 prcdia_plsdg3ac INT(1) UNSIGNED, \
 prcdia_plsdg3b0 INT(1) UNSIGNED, \
 prcdia_plsdg3b4 INT(1) UNSIGNED, \
 prcdia_plsdg3b8 INT(1) UNSIGNED, \
 prcdia_plsdg3bc INT(1) UNSIGNED, \
 prcdia_plsdg3c0 INT(1) UNSIGNED, \
 prcdia_plsdg3c4 INT(1) UNSIGNED, \
 prcdia_plsdg3c8 INT(1) UNSIGNED, \
 prcdia_plsdg3cc INT(1) UNSIGNED, \
 prcdia_plsdg3d0 INT(1) UNSIGNED, \
 prcdia_plsdg3d4 INT(1) UNSIGNED, \
 prcdia_plsdg3d8 INT(1) UNSIGNED, \
 prcdia_plsdg3dc INT(1) UNSIGNED, \
 prcdia_plsdg3e0 INT(1) UNSIGNED, \
 prcdia_plsdg3e4 INT(1) UNSIGNED, \
 prcdia_plsdg3e8 INT(1) UNSIGNED, \
 prcdia_plsdg3ec INT(1) UNSIGNED, \
 prcdia_plsdg3f0 INT(1) UNSIGNED, \
 prcdia_plsdg3f4 INT(1) UNSIGNED, \
 prcdia_plsdg3f8 INT(1) UNSIGNED, \
 prcdia_plsdg3fc INT(1) UNSIGNED, \
 prcdia_plstotdi INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";


//DOMAIN-6's TABLE

const char *query_create_d6r1 =
 "CREATE TABLE IF NOT EXISTS d6r1 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodvon_rdevtype TINYINT(1) UNSIGNED, \
 iodvon_rdevclas TINYINT(1) UNSIGNED, \
 iodvon_rdevdvid SMALLINT(1) UNSIGNED, \
 iodvon_calmodln TINYINT(1) UNSIGNED, \
 iodvon_rdevlpm TINYINT(1) UNSIGNED, \
 iodvon_rdevdev SMALLINT(1) UNSIGNED, \
 iodvon_rdevsid INT(1) UNSIGNED, \
 iodvon_rdevchps CHAR(8), \
 iodvon_rdevcuid SMALLINT(1) UNSIGNED, \
 iodvon_rdevcumn TINYINT(1) UNSIGNED, \
 iodvon_calflags TINYINT(1) UNSIGNED, \
 iodvon_rdcrcuc CHAR(1), \
 iodvon_rdcobrco CHAR(1), \
 iodvon_rdevser CHAR(6), \
 iodvon_calrdevsid INT(1) UNSIGNED, \
 iodvon_calrdevdev SMALLINT(1) UNSIGNED, \
 iodvon_rdevpvfg TINYINT(1) UNSIGNED, \
 iodvon_edevtype TINYINT(1) UNSIGNED, \
 iodvon_edevpth1 CHAR(20), \
 iodvon_edevfcp1 CHAR(2), \
 iodvon_edevwpn1 CHAR(8), \
 iodvon_edevlun1 CHAR(8), \
 iodvon_edevpth2 CHAR(20), \
 iodvon_edevfcp2 CHAR(2), \
 iodvon_edevwpn2 CHAR(8), \
 iodvon_edevlun2 CHAR(8), \
 iodvon_edevpth3 CHAR(20), \
 iodvon_edevfcp3 CHAR(2), \
 iodvon_edevwpn3 CHAR(8), \
 iodvon_edevlun3 CHAR(8), \
 iodvon_edevpth4 CHAR(20), \
 iodvon_edevfcp4 CHAR(2), \
 iodvon_edevwpn4 CHAR(8), \
 iodvon_edevlun4 CHAR(8), \
 iodvon_edevpth5 CHAR(20), \
 iodvon_edevfcp5 CHAR(2), \
 iodvon_edevwpn5 CHAR(8), \
 iodvon_edevlun5 CHAR(8), \
 iodvon_edevpth6 CHAR(20), \
 iodvon_edevfcp6 CHAR(2), \
 iodvon_edevwpn6 CHAR(8), \
 iodvon_edevlun6 CHAR(8), \
 iodvon_edevpth7 CHAR(20), \
 iodvon_edevfcp7 CHAR(2), \
 iodvon_edevwpn7 CHAR(8), \
 iodvon_edevlun7 CHAR(8), \
 iodvon_edevpth8 CHAR(20), \
 iodvon_edevfcp8 CHAR(2), \
 iodvon_edevwpn8 CHAR(8), \
 iodvon_edevlun8 CHAR(8), \
 iodvon_prefpath TINYINT(1) UNSIGNED, \
 iodvon_rdevhppl SMALLINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r2 =
 "CREATE TABLE IF NOT EXISTS d6r2 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodvof_rdevsid INT(1) UNSIGNED, \
 iodvof_rdevdev SMALLINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r5 =
 "CREATE TABLE IF NOT EXISTS d6r5 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodatd_rdevtype TINYINT(1) UNSIGNED, \
 iodatd_rdevclas TINYINT(1) UNSIGNED, \
 iodatd_rdevdvid SMALLINT(1) UNSIGNED, \
 iodatd_calmodln TINYINT(1) UNSIGNED, \
 iodatd_rdevlpm TINYINT(1) UNSIGNED, \
 iodatd_rdevdev SMALLINT(1) UNSIGNED, \
 iodatd_rdevsid INT(1) UNSIGNED, \
 iodatd_rdevchps CHAR(8), \
 iodatd_rdevcuid SMALLINT(1) UNSIGNED, \
 iodatd_rdevcumn TINYINT(1) UNSIGNED, \
 iodatd_calflags TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r6 =
 "CREATE TABLE IF NOT EXISTS d6r6 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 ioddtd_rdevsid INT(1) UNSIGNED, \
 ioddtd_rdevdev SMALLINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r7 =
 "CREATE TABLE IF NOT EXISTS d6r7 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodenb_rdevsid INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r8 =
 "CREATE TABLE IF NOT EXISTS d6r8 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 ioddsb_rdevsid INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r12 =
 "CREATE TABLE IF NOT EXISTS d6r12 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodsof_rdevsid INT(1) UNSIGNED, \
 iodsof_rdevdev SMALLINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r13 =
 "CREATE TABLE IF NOT EXISTS d6r13 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodmon_rdevsid INT(1) UNSIGNED, \
 iodmon_rdevdev SMALLINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r14 =
 "CREATE TABLE IF NOT EXISTS d6r14 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodmof_rdevsid INT(1) UNSIGNED, \
 iodmof_rdevdev SMALLINT(1) UNSIGNED, \
 iodmof_scmssch SMALLINT(1) UNSIGNED, \
 iodmof_scmcount SMALLINT(1) UNSIGNED, \
 iodmof_scmcntim INT(1) UNSIGNED, \
 iodmof_scmfptim INT(1) UNSIGNED, \
 iodmof_scmddtim INT(1) UNSIGNED, \
 iodmof_scmcqtim INT(1) UNSIGNED, \
 iodmof_scmdatim INT(1) UNSIGNED, \
 iodmof_scmdbtim INT(1) UNSIGNED, \
 iodmof_scmirtim INT(1) UNSIGNED, \
 iodmof_scgssch INT(1) UNSIGNED, \
 iodmof_scgcount INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r15 =
 "CREATE TABLE IF NOT EXISTS d6r15 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodddv_rdevsid INT(1) UNSIGNED, \
 iodddv_rdevdev SMALLINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r17 =
 "CREATE TABLE IF NOT EXISTS d6r17 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 ioddch_calchpid INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r22 =
 "CREATE TABLE IF NOT EXISTS d6r22 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodvsf_lanowner CHAR(8), \
 iodvsf_lanname CHAR(8), \
 iodvsf_lanrdd_lancont CHAR(8), \
 iodvsf_lanrdd_rdev SMALLINT(1) UNSIGNED, \
 iodvsf_lanrdd_osaport TINYINT(1) UNSIGNED, \
 iodvsf_lanmgipa INT(1) UNSIGNED, \
 iodvsf_mgswieuser CHAR(8), \
 iodvsf_mgnicmac BINARY(6), \
 iodvsf_swpgroup CHAR(8), \
 iodvsf_lanrdd_rsn TINYINT(1) UNSIGNED, \
 iodvsf_vqstate TINYINT(1) UNSIGNED, \
 iodvsf_vqsreas SMALLINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r23 =
 "CREATE TABLE IF NOT EXISTS d6r23 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodvsr_lanowner CHAR(8), \
 iodvsr_lanname CHAR(8), \
 iodvsr_lanrdd_lancont CHAR(8), \
 iodvsr_lanrdd_rdev SMALLINT(1) UNSIGNED, \
 iodvsr_lanrdd_osaport TINYINT(1) UNSIGNED, \
 iodvsr_swiecapab INT(1) UNSIGNED, \
 iodvsr_lanmgipa INT(1) UNSIGNED, \
 iodvsr_mgswieuser CHAR(8), \
 iodvsr_mgnicmac BINARY(6), \
 iodvsr_swpgroup CHAR(8), \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";


const char *query_create_d6r24 =
 "CREATE TABLE IF NOT EXISTS d6r24 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodszi_rdevdev SMALLINT(1) UNSIGNED, \
 iodszi_dskstat TINYINT(1) UNSIGNED, \
 iodszi_dsktime INT(1) UNSIGNED, \
 iodszi_dskxrate INT(1) UNSIGNED, \
 iodszi_dskblksz INT(1) UNSIGNED, \
 iodszi_dskxfers INT(1) UNSIGNED, \
 iodszi_dskblksr INT(1) UNSIGNED, \
 iodszi_dskblksw INT(1) UNSIGNED, \
 iodszi_dskseeko INT(1) UNSIGNED, \
 iodszi_dskqdepth INT(1) UNSIGNED, \
 iodszi_pth1id SMALLINT(1) UNSIGNED, \
 iodszi_pth1stat TINYINT(1) UNSIGNED, \
 iodszi_pth1time INT(1) UNSIGNED, \
 iodszi_pth1xrate INT(1) UNSIGNED, \
 iodszi_pth1xfers INT(1) UNSIGNED, \
 iodszi_pth1blksr INT(1) UNSIGNED, \
 iodszi_pth1blksw INT(1) UNSIGNED, \
 iodszi_pth1seeko INT(1) UNSIGNED, \
 iodszi_pth1qdepth INT(1) UNSIGNED, \
 iodszi_pth2id SMALLINT(1) UNSIGNED, \
 iodszi_pth2stat TINYINT(1) UNSIGNED, \
 iodszi_pth2time INT(1) UNSIGNED, \
 iodszi_pth2xrate INT(1) UNSIGNED, \
 iodszi_pth2xfers INT(1) UNSIGNED, \
 iodszi_pth2blksr INT(1) UNSIGNED, \
 iodszi_pth2blksw INT(1) UNSIGNED, \
 iodszi_pth2seeko INT(1) UNSIGNED, \
 iodszi_pth2qdepth INT(1) UNSIGNED, \
 iodszi_pth3id SMALLINT(1) UNSIGNED, \
 iodszi_pth3stat TINYINT(1) UNSIGNED, \
 iodszi_pth3time INT(1) UNSIGNED, \
 iodszi_pth3xrate INT(1) UNSIGNED, \
 iodszi_pth3xfers INT(1) UNSIGNED, \
 iodszi_pth3blksr INT(1) UNSIGNED, \
 iodszi_pth3blksw INT(1) UNSIGNED, \
 iodszi_pth3seeko INT(1) UNSIGNED, \
 iodszi_pth3qdepth INT(1) UNSIGNED, \
 iodszi_pth4id SMALLINT(1) UNSIGNED, \
 iodszi_pth4stat TINYINT(1) UNSIGNED, \
 iodszi_pth4time INT(1) UNSIGNED, \
 iodszi_pth4xrate INT(1) UNSIGNED, \
 iodszi_pth4xfers INT(1) UNSIGNED, \
 iodszi_pth4blksr INT(1) UNSIGNED, \
 iodszi_pth4blksw INT(1) UNSIGNED, \
 iodszi_pth4seeko INT(1) UNSIGNED, \
 iodszi_pth4qdepth INT(1) UNSIGNED, \
 iodszi_pth5id SMALLINT(1) UNSIGNED, \
 iodszi_pth5stat TINYINT(1) UNSIGNED, \
 iodszi_pth5time INT(1) UNSIGNED, \
 iodszi_pth5xrate INT(1) UNSIGNED, \
 iodszi_pth5xfers INT(1) UNSIGNED, \
 iodszi_pth5blksr INT(1) UNSIGNED, \
 iodszi_pth5blksw INT(1) UNSIGNED, \
 iodszi_pth5seeko INT(1) UNSIGNED, \
 iodszi_pth5qdepth INT(1) UNSIGNED, \
 iodszi_pth6id SMALLINT(1) UNSIGNED, \
 iodszi_pth6stat TINYINT(1) UNSIGNED, \
 iodszi_pth6time INT(1) UNSIGNED, \
 iodszi_pth6xrate INT(1) UNSIGNED, \
 iodszi_pth6xfers INT(1) UNSIGNED, \
 iodszi_pth6blksr INT(1) UNSIGNED, \
 iodszi_pth6blksw INT(1) UNSIGNED, \
 iodszi_pth6seeko INT(1) UNSIGNED, \
 iodszi_pth6qdepth INT(1) UNSIGNED, \
 iodszi_pth7id SMALLINT(1) UNSIGNED, \
 iodszi_pth7stat TINYINT(1) UNSIGNED, \
 iodszi_pth7time INT(1) UNSIGNED, \
 iodszi_pth7xrate INT(1) UNSIGNED, \
 iodszi_pth7xfers INT(1) UNSIGNED, \
 iodszi_pth7blksr INT(1) UNSIGNED, \
 iodszi_pth7blksw INT(1) UNSIGNED, \
 iodszi_pth7seeko INT(1) UNSIGNED, \
 iodszi_pth7qdepth INT(1) UNSIGNED, \
 iodszi_pth8id SMALLINT(1) UNSIGNED, \
 iodszi_pth8stat TINYINT(1) UNSIGNED, \
 iodszi_pth8time INT(1) UNSIGNED, \
 iodszi_pth8xrate INT(1) UNSIGNED, \
 iodszi_pth8xfers INT(1) UNSIGNED, \
 iodszi_pth8blksr INT(1) UNSIGNED, \
 iodszi_pth8blksw INT(1) UNSIGNED, \
 iodszi_pth8seeko INT(1) UNSIGNED, \
 iodszi_pth8qdepth INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r25 =
 "CREATE TABLE IF NOT EXISTS d6r25 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodqda_rdevdev SMALLINT(1) UNSIGNED, \
 iodqda_vmduser CHAR(8), \
 iodqda_vdevdev SMALLINT(1) UNSIGNED, \
 iodqda_qdiofmt SMALLINT(1) UNSIGNED, \
 iodqda_qdinpct SMALLINT(1) UNSIGNED, \
 iodqda_qdioutct SMALLINT(1) UNSIGNED, \
 iodqda_status BINARY(4), \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r26 =
 "CREATE TABLE IF NOT EXISTS d6r26 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodqds_rdevdev SMALLINT(1) UNSIGNED, \
 iodqds_qdiocsgr INT(1) UNSIGNED, \
 iodqds_qdiocsgw INT(1) UNSIGNED, \
 iodqds_qdiocsgs INT(1) UNSIGNED, \
 iodqds_rdevvssr INT(1) UNSIGNED, \
 iodqds_rdevvssw INT(1) UNSIGNED, \
 iodqds_rdevvsss INT(1) UNSIGNED, \
 iodqds_bftoa BINARY(8), \
 iodqds_bytoa BINARY(8), \
 iodqds_bffra BINARY(8), \
 iodqds_byfra BINARY(8), \
 iodqds_rdevvsin INT(1) UNSIGNED, \
 iodqds_rdevvsir INT(1) UNSIGNED, \
 iodqds_rdevvsid INT(1) UNSIGNED, \
 iodqds_qsbsqbvm INT(1) UNSIGNED, \
 iodqds_qsbsqbpv INT(1) UNSIGNED, \
 iodqds_qsbeqbvm INT(1) UNSIGNED, \
 iodqds_qsbeqbpv INT(1) UNSIGNED, \
 iodqds_qsblock INT(1) UNSIGNED, \
 iodqds_qsbfobx INT(1) UNSIGNED, \
 iodqds_qsbolck INT(1) UNSIGNED, \
 iodqds_qsbsigwt INT(1) UNSIGNED, \
 iodqds_qsbsigrt INT(1) UNSIGNED, \
 iodqds_qsbsiglt INT(1) UNSIGNED, \
 iodqds_sumofpin INT(1) UNSIGNED, \
 iodqds_sumunpin INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r27 =
 "CREATE TABLE IF NOT EXISTS d6r27 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodqdd_rdevdev SMALLINT(1) UNSIGNED, \
 iodqdd_qdiocsgr INT(1) UNSIGNED, \
 iodqdd_qdiocsgw INT(1) UNSIGNED, \
 iodqdd_qdiocsgs INT(1) UNSIGNED, \
 iodqdd_rdevvssr INT(1) UNSIGNED, \
 iodqdd_rdevvssw INT(1) UNSIGNED, \
 iodqdd_rdevvsss INT(1) UNSIGNED, \
 iodqdd_bftoa BINARY(8), \
 iodqdd_bytoa BINARY(8), \
 iodqdd_bffra BINARY(8), \
 iodqdd_byfra BINARY(8), \
 iodqdd_rdevvsin INT(1) UNSIGNED, \
 iodqdd_rdevvsir INT(1) UNSIGNED, \
 iodqdd_rdevvsid INT(1) UNSIGNED, \
 iodqdd_qsbsqbvm INT(1) UNSIGNED, \
 iodqdd_qsbsqbpv INT(1) UNSIGNED, \
 iodqdd_qsbeqbvm INT(1) UNSIGNED, \
 iodqdd_qsbeqbpv INT(1) UNSIGNED, \
 iodqdd_qsblock INT(1) UNSIGNED, \
 iodqdd_qsbfobx INT(1) UNSIGNED, \
 iodqdd_qsbolck INT(1) UNSIGNED, \
 iodqdd_qsbsigwt INT(1) UNSIGNED, \
 iodqdd_qsbsigrt INT(1) UNSIGNED, \
 iodqdd_qsbsiglt INT(1) UNSIGNED, \
 iodqdd_sumofpin INT(1) UNSIGNED, \
 iodqdd_sumunpin INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r28 =
 "CREATE TABLE IF NOT EXISTS d6r28 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodhpp_hppoolnm SMALLINT(1) UNSIGNED, \
 iodhpp_hpptoken SMALLINT(1) UNSIGNED, \
 iodhpp_hppnbase INT(1) UNSIGNED, \
 iodhpp_hppnalis INT(1) UNSIGNED, \
 iodhpp_hpptries INT(1) UNSIGNED, \
 iodhpp_hppfails INT(1) UNSIGNED, \
 iodhpp_hppminct INT(1) UNSIGNED, \
 iodhpp_hppmaxct INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r29 =
 "CREATE TABLE IF NOT EXISTS d6r29 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodhpc_hppoolnm SMALLINT(1) UNSIGNED, \
 iodhpc_hpptoken SMALLINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d6r30 =
 "CREATE TABLE IF NOT EXISTS d6r30 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 iodlpt_cuidssid SMALLINT(1) UNSIGNED, \
 iodlpt_cuipvopr_old TINYINT(1) UNSIGNED, \
 iodlpt_cuipvopr_new TINYINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";


//DOMAIN-7's TABLE
const char *query_create_d7r1 =
 "CREATE TABLE IF NOT EXISTS d7r1 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP UNIQUE, \
 seksek_rdevsid INT(1) UNSIGNED, \
 seksek_calcurcy SMALLINT(1) UNSIGNED, \
 seksek_calskcyl SMALLINT(1) UNSIGNED, \
 seksek_calskhd SMALLINT(1) UNSIGNED, \
 seksek_calflags TINYINT(1) UNSIGNED, \
 seksek_vmduser CHAR(8), \
 seksek_iorposct INT(1) UNSIGNED, \
 seksek_iorpossm INT(1) UNSIGNED, \
 seksek_calecyl SMALLINT(1) UNSIGNED, \
 seksek_vdevdev SMALLINT(1) UNSIGNED, \
 seksek_caluser CHAR(8), \
 seksek_rvdevdev SMALLINT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

//DOMAIN-8's TABLE

//NEED TEST OF INDEXES --UNIQUE
const char *query_create_d8r1 =
 "CREATE TABLE IF NOT EXISTS d8r1 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP, \
 vndses_vdevsub SMALLINT(1) UNSIGNED, \
 vndses_owner CHAR(8), \
 vndses_vdevdev SMALLINT(1) UNSIGNED, \
 vndses_nicbase SMALLINT(1) UNSIGNED, \
 vndses_nicmac BINARY(6), \
 vndses_nictranp TINYINT(1) UNSIGNED, \
 vndses_nictype CHAR(1), \
 vndses_lanid CHAR(16), \
 vndses_vswitch  TINYINT(1) UNSIGNED, \
 vndses_nic_lockreqs  BINARY(8), \
 vndses_landefer BINARY(8), \
 vndses_txdefers BINARY(8), \
 vndses_rxdefers BINARY(8), \
 vndses_sestxbyt BINARY(8), \
 vndses_sesrxbyt BINARY(8), \
 vndses_sestxpkt BINARY(8), \
 vndses_sestxdsc BINARY(8), \
 vndses_sestxerr BINARY(8), \
 vndses_sesrxpkt BINARY(8), \
 vndses_sesrxdsc BINARY(8), \
 vndses_sesrxerr BINARY(8), \
 vndses_sesrxpci BINARY(8), \
 vndses_sestxpci BINARY(8), \
 vndses_swpgroup CHAR(8), \
 vndses_swpintsc SMALLINT(1) UNSIGNED, \
 vndses_niddvnum1 SMALLINT(1) UNSIGNED, \
 vndses_vrtpfrme1 INT(1) UNSIGNED, \
 vndses_niddvnum2 SMALLINT(1) UNSIGNED, \
 vndses_vrtpfrme2 INT(1) UNSIGNED, \
 vndses_niddvnum3 SMALLINT(1) UNSIGNED, \
 vndses_vrtpfrme3 INT(1) UNSIGNED, \
 vndses_niddvnum4 SMALLINT(1) UNSIGNED, \
 vndses_vrtpfrme4 INT(1) UNSIGNED, \
 vndses_niddvnum5 SMALLINT(1) UNSIGNED, \
 vndses_vrtpfrme5 INT(1) UNSIGNED, \
 vndses_niddvnum6 SMALLINT(1) UNSIGNED, \
 vndses_vrtpfrme6 INT(1) UNSIGNED, \
 vndses_niddvnum7 SMALLINT(1) UNSIGNED, \
 vndses_vrtpfrme7 INT(1) UNSIGNED, \
 vndses_niddvnum8 SMALLINT(1) UNSIGNED, \
 vndses_vrtpfrme8 INT(1) UNSIGNED, \
 vndses_txreqshi INT(1) UNSIGNED, \
 vndses_txreqslo INT(1) UNSIGNED, \
 vndses_rxreqshi INT(1) UNSIGNED, \
 vndses_rxreqslo INT(1) UNSIGNED, \
 vndses_stkreqhi INT(1) UNSIGNED, \
 vndses_stkreqlo INT(1) UNSIGNED, \
 vndses_stkdefershi INT(1) UNSIGNED, \
 vndses_stkdeferslo INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d8r2 =
 "CREATE TABLE IF NOT EXISTS d8r2 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP UNIQUE, \
 vndlsu_lanowner CHAR(8), \
 vndlsu_lanname CHAR(8), \
 vndlsu_nicowner CHAR(8), \
 vndlsu_nicbase SMALLINT(1) UNSIGNED, \
 vndlsu_nicmgpor INT(1) UNSIGNED, \
 vndlsu_nicmgifi INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

const char *query_create_d8r3 =
 "CREATE TABLE IF NOT EXISTS d8r3 (\
 id BIGINT AUTO_INCREMENT, \
 time TIMESTAMP UNIQUE, \
 vndlsd_lanowner CHAR(8), \
 vndlsd_lanname CHAR(8), \
 vndlsd_nicowner CHAR(8), \
 vndlsd_nicbase SMALLINT(1) UNSIGNED, \
 vndlsd_nicmgpor INT(1) UNSIGNED, \
 vndlsd_nicmgifi INT(1) UNSIGNED, \
 PRIMARY KEY (id)) ENGINE=ARCHIVE";

#ifdef	__cplusplus
}
#endif

#endif	/* _CREATE_TABLES_H */
