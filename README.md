# Mefislator - Simulador de entrada e saída (arquivos)

**Hugo Gomes, Matheus Schulz, João Vitor de Oliveira**<br>
**Trabalho final - Sistemas Operacionais 2017/1**<br>
**Professora: Valéria Bastos**<br>
** **

Com o intuito de ilustrar conceitos vistos ao longo da disciplina, em particular o funcionamento de um gerenciador de entrada e saída e o de arquivos, foi desenvolvido um simulador que replicasse as operações realizadas pelo sistema operacional nestes gerenciadores. O código em linguagem C se encontra disponível em: <br>
https://github.com/Hugodovs/OS-Simulator

### Dispositivos presentes no simulador
** **

  - Memória RAM (memória primária)
  - Disco rígido (memória secundária), com sua controladora
  - Processador

### Visão geral do código fonte
** **

  - *main.c* (arquivo principal)
  - *memory.c* (contém a lógica de transferência de dados no disco rígido e na memória RAM)
  - *screen.c* (interface gráfica do utilizador)
  - *directory_table.c* (contém a lógica envolvendo a *Directory Table*)
  - *descriptor_table.c* (contém a lógica envolvendo a *Inode Table*)
  - *ram_file_table* (contém a lógica envolvendo arquivos carregados na RAM)

### Estruturas de Dados
** **
Para que a simulação fosse possível, foi imperativa a criação de algumas estruturas de dados em cada uma das componentes.


##### Estruras no disco rígido
****
###### Directory Table
|endereço lógico (string - ex: "file.txt")| Inode number|
| ------------- |:-------------:|

###### Inode Table
|Inode number | endereço físico (int) | tamanho |
| ------------- |:-------------:|-------------:|

###### Disk file Table
|conteúdo|
| ------------- |

###### Acess_Matrix
|users | file1 | file2 | file3 |
| ------------- |:-------------:|-------------:|-------------:|
##### Estruras na memória RAM
****
###### File RAM Table
|endereço lógico (string) | Inode number | RAM adress | tamanho | file pointer | mode | 
| ------------- |:-------------:|-------------:|-------------:|-------------:|-------------:|
###### RAM Table
|conteúdo | 
| ------------- |

### Operações implementadas
****


##### open
Esta operação é capaz de abrir um arquivo solicitado. Caso este arquivo não exista, um novo será criado com este mesmo nome. Um exemplo de uso do comando seria:
```
open exercicioSO.txt
```
1. Kernel verifica se arquivo existe usando a Directory_Table. Se não existir, um arquivo como nome informado é criado.
2. Kernel faz o parsing do endereço lógico informado para um Inode number (pela verificação prévia na Directory_Table). Na Inode Table consta os blocos de onde o arquivo se localiza no disco para cada Inode number. 
2. Controladora de disco recebe a requisição e solicita a controladora DMA que sejam transmitidos os blocos de dados referente ao que estava na Inode Table.
3. Com o endereço físico, o controlador do disco transfere o conteúdo (Disk_file_Table) para a  controladora_DMA.
4. A controladora_DMA envia o conteúdo a memória RAM.
5. Enfim tem-se o arquivo na RAM (File_RAM_Table atualizada).




##### delete
Esta operação é capaz de apagar um arquivo solicitado. Caso este arquivo não exista, uma mensagem de erro é impressa ao usuário. Um exemplo de uso do comando seria:
```
delete java.txt
```

Etapas envolvidas nesta operação:
1. Kernel verifica se arquivo existe usando a Directory_Table. Se não existir, um arquivo como nome informado é criado.
2. Kernel faz o parsing do endereço lógico informado para um Inode number (pela verificação prévia na Directory_Table). Na Inode Table consta os blocos de onde o arquivo se localiza no disco (endereço físico) para cada Inode number.
3. Controladora de disco recebe a requisição constando os blocos de dados a serem apagados no disco.
4. Processador recebe a informação de que o dado foi apagado fisicamente.
5. Directory Table  e Inode Table são atualizadas.


##### read
Esta operação é capaz de apagar um arquivo solicitado. Caso este arquivo não exista, uma mensagem de erro é impressa ao usuário. Um exemplo de uso do comando seria:
```
read java.txt 
```
##### write

##### close






