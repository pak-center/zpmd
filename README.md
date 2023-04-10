# zpmd
![GitHub top language](https://img.shields.io/github/languages/top/pak-center/zpmd?style=plastic)
[![Scc Count Badge](https://sloc.xyz/github/pak-center/zpmd/)](https://github.com/pak-center/zpmd/)
[![Scc Count Badge](https://sloc.xyz/github/pak-center/zpmd/?category=code)](https://github.com/pak-center/zpmd/)
[![Scc Count Badge](https://sloc.xyz/github/pak-center/zpmd/?category=comments)](https://github.com/pak-center/zpmd/)
[![Scc Count Badge](https://sloc.xyz/github/pak-center/zpmd/?category=blanks)](https://github.com/pak-center/zpmd/)
![GitHub repo size](https://img.shields.io/github/repo-size/pak-center/zpmd?style=plastic)
![GitHub](https://img.shields.io/github/license/pak-center/zpmd?style=plastic)

### Obsolete code from BE thesis.

z/VM Performance Monitor Daemon: zpmd for z/Linux running under z/VM on IBM mainframe. It processes and gathers data from DCSS used by Monitor System Service (*MONITOR). Records are written to MySQL database. 

## Changelog

### Features >= v1.0.0 (not uploaded on github yet)

- works with z/VM V5.3 records
- may be extended to use other records e.g. z/VM V7.3
- blocking READ (non-blocking READ is provided in Rust language project called zEM)
- two threads (1st as main for DB INSERTS, 2nd for READ from /dev and buffers managing)
- uses two buffers but needs 2x more memory (2x MONDCSS size)
- operates on MySQL DB (single database - multiple tables, like d0r3 type records have their own table)
- database engine = Archive without indexes on tables

### Features <= v0.9.0 (current alpha)

- works with z/VM V5.3 records
- blocking read
- single thread
- single buffer
- operates on MySQL DB (single database - multiple tables, like d0r3 type records have their own table)
- database engine = InnoDB with indexes on tables

## Supported Domains and Records by zpmd v0.9.0 & MySQL database INSERT

| Domain | V5.3 Records | V5.3 handled | % Progress |
| :---: | :---: | :---: | :---: |
| 0 | 24 | 15 | 63% |
| 1 | 20 | 11 | 55% |
| 2 | 12 | 10 | 83% |
| 3 | 20 | 20 | Complete |
| 4 | 10 | 5 | 50% |
| 5 | 12 | 9 | 75% |
| 6 | 30 | 20 | 67% |
| 7 | 1 | 1 | Complete |
| 8 | 3 | 3 | Complete |
| 9 | n/n | n/n | n/n |
| 10 | 2 | 0 | 0% |

### TODO:

- [ ] implement full handling of z/VM 5.3 records set 
- [ ] remove question about DCSS size
- [X] code fix & rename variables names from Polish to English languge
- [ ] refactoring code from legacy v0.9.0 to v1.0.0-alpha1

---

[![License: GPL v2](https://img.shields.io/badge/License-GPL_v2-blue.svg)](https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html)
![Lines of code](https://img.shields.io/tokei/lines/github/pak-center/zpmd?label=total%20lines%20of%20code&style=plastic)
