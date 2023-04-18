/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"

#include "synchconsole.h"

typedef int OpenFileId;

void SysHalt()
{
  kernel->interrupt->Halt();
}

void SysPrintInt(int value)
{
	kernel->synchConsoleOut->PutInt(value);
}

int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysCreate(char *filename)
{
	// return value
	// 1: success
	// 0: failed
	return kernel->interrupt->CreateFile(filename);
}

OpenFileId SysOpen(char *filename)
{
	return kernel->interrupt->OpenFile(filename);
}

int SysWrite(char *buffer, int size, OpenFileId fd)
{
	return kernel->interrupt->WriteFile(buffer, size, fd);
}

int SysClose(OpenFileId fd)
{
	return kernel->interrupt->CloseFile(fd);
}

int SysRead(char *buffer, int size, OpenFileId fd)
{
	return kernel->interrupt->ReadFile(buffer, size, fd);
}

#endif /* ! __USERPROG_KSYSCALL_H__ */
