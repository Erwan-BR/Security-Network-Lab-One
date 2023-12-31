#include "./mainQuestion2.h"

void mainQuestion2()
{
    printf("Inversion of a file containing \"Hello World!\".\n");

    // ./ Because this function is called from main.
    const char inputDirectory[] = "./textFiles/input_exo_2.txt";

    // 2. Open the file
    int openFile = open(inputDirectory, O_RDWR);
    if (-1 == openFile)
    {
        perror("ERROR on open");
        return ;
    }
    printf("The file has been opened.\n\n");
    struct stat statsOfFile;

    // 2. Get the size of the file
    int fileStats = fstat(openFile, &statsOfFile);
    if (-1 == fileStats)
    {
        perror("ERROR on fstat");
        return ;
    }
    printf("Size of file: %ld bytes.\n\n", statsOfFile.st_size);

    // 3. Mapping the file into memory
    char* mappedData = mmap(NULL, statsOfFile.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, openFile, 0);
    printf("The file has been mapped in memory.\n");

    // 4. Inverse bytes of the file in memory.
    for (long int index = 0; index < statsOfFile.st_size/2 ; index++)
    {
        char temporary = mappedData[index];
        mappedData[index] = mappedData[statsOfFile.st_size - index - 1];
        mappedData[statsOfFile.st_size - index - 1] = temporary;
    }
    printf("Bytes of the file have been reversed.\n");

    // 5. End the mapping and propagate the info.
    int unmappedData = munmap(mappedData, statsOfFile.st_size);
    if (-1 == unmappedData)
    {
        perror("ERROR on munmap");
    }
    int fsyncData = fsync(openFile);
    if (-1 == fsyncData)
    {
        perror("ERROR on fsync");
    }
    int closedFile = close(openFile);
    if (-1 == closedFile)
    {
        perror("ERROR on close");
    }

    printf("The file has been unmapped and synchronization forced.\n");
}