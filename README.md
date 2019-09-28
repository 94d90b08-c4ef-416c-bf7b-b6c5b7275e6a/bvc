# Here we go

> Если у тебя возникла умная мысль - запиши её.  
> Так она становится яснее, а глупость, заключенная в ней - очевиднее.  

## LVMCore
Req: lvm2-devel
https://fedoraproject.org/wiki/LVM/liblvm
https://github.com/malachheb/liblvm/blob/master/ext/liblvm.c 

Main puprose is to use LVM thin pool abstraction to realize version control for huge binary data that need to be under VCS, but most of them are useless.  
## It should let U to:
- **initialize** repository within LVM VG  
- **commit** changes on device  
- **switch** onto some commit  
- **tag** revision with meaningful description  
- **export** data partition  
- **view** commits history  

## It may:
- determine current repository state (data consistent) by using explicit locks or some side-defined attr
- generate some advices (to make commit or rollback) by current data state
- export whole repository, files only

## It is not possible
to find out exact changes, so
- you can't merge two state
- you can't figure out sufficient diference between two commits

**Possible diff workarounds**:  
- use block-level: provide us block-level diff and ability to merge them  
- use file-level diff: provide more sufficient changes, requires much overhead during work (as docker do it)  

## think of
- low level FS (xfs? btrfs?) tuning  
- use dm directly (realize thin pool by bare hands)  

## Underware

### Env
- ruby 2.3.3
- Fedora 25
- bash 4.3.43
- LVM 2.02.167

