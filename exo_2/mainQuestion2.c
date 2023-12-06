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
    struct stat statsOfFile;

    // 2. Get the size of the file
    int fileStats = fstat(openFile, &statsOfFile);
    if (-1 == fileStats)
    {
        perror("ERROR on fstat");
        return ;
    }
    printf("Size of file: %ld bytes.\n", statsOfFile.st_size);

    // 3. Mapping the file into memory
    char* mappedData = mmap(NULL, statsOfFile.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, openFile, 0);

    // 4. Inverse bytes of the file in memory.
    for (long int index = 0; index < statsOfFile.st_size/2 ; index++)
    {
        char temporary = mappedData[index];
        mappedData[index] = mappedData[statsOfFile.st_size - index - 1];
        mappedData[statsOfFile.st_size - index - 1] = temporary;
    }

    // 5. End the mapping and propagate the info.
    munmap(NULL, statsOfFile.st_size);
    fsync(openFile);
}