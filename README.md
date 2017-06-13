
NOSSO SISTEMA DE ARQUIVO, Private National Computer Visualizer  

Estruturas que estão no HD:

* Directory_Table: 	+---------------------------------------+--------------+
					| endereço lógico (string - "file.txt") | Inode number |
					|										|			   |
					+---------------------------------------+--------------+

* Inode_Table: +--------------+-------------------------------+---------+
			   | Inode number | endereço físico (int - 52352) | tamanho |
			   |			  |			    				  | 		|
			   +--------------+-------------------------------+---------+

* Disk_file_Table: +--------+
				   |conteúdo|				
				   |		|
				   +--------+

Estruturas que estão na RAM:

* Virtual_Directory_Table: 	+---------------------------------------+--------------+
							| endereço lógico (string - "file.txt") | Inode number |
							|										|			   |
							+---------------------------------------+--------------+

* File_RAM_Table: 

  +--------------+------------+---------+--------------+------+------------+
  | Inode number | RAM adress | tamanho | file pointer | mode | permission |
  |				 |			  |			|              |	  |			   |
  +--------------+------------+---------+--------------+------+------------+

* RAM_Table:

				   +--------+
				   |conteúdo|
				   |		|
				   +--------+


Operações que o processador faz para a  controladora_DMA (usando DMA):

Comandos do usuário

	open ("file.txt"):
		Faz uma requisição passando nome do arquivo para a  controladora_DMA passar o arquivo no HD para a RAM.
		Controladora_DMA recebe uma requisição para abrir com o endereço lógico "file.txt"
		Ela manda para o controlador do disco, mapear.
		O controlador do disco, transforma o "file.txt" usando o Directory_Table.
		Tendo o Inumber, o controlador do disco usa o Inode_Table para pegar o endereço físico e o tamanho.
		Com o endereço físico, o controlador do disco pega o conteúdo e passa para a  controladora_DMA.
		A  controladora_DMA passa pra RAM.
		Finalmente temos o arquivo na RAM.

	delete ("file.txt"):
		Faz uma requisição passando nome do arquivo para a  controladora_DMA remover o arquivo do HD.
		controladora_DMA recebe uma requisição para abrir com o endereço lógico "file.txt"
		O controlador do disco, transforma o "file.txt" usando o Directory_Table.
		Tendo o Inumber, o controlador do disco usa o Inode_Table para pegar o endereço físico e o tamanho.
		Com o endereço físico, o controlador do disco pega o conteúdo e passa para a  controladora_DMA.
		O controlador do Disco apaga o conteúdo do arquivo, e os "entrys".
		Finalmente temos o aquivo fora do HD.

	read ("file.txt") size

		Pega o conteúdo do arquivo na ram e, printa.

	close ("file.txt")
		Faz uma requisição para a  controladora_DMA passar da RAM para o HD

	write "string" in int(address):
		Escreve um conjunto de caracteres no endereço e vai seguindo

