# Simulador de entrada e saída (arquivos)

**Hugo Gomes, Matheus Schulz, João Vitor de Oliveira**
**Trabalho final - Sistemas Operacionais 2017/1**
**Professora: Valéria Bastos**
** **

Com o intuito de ilustrar conceitos vistos ao longo da disciplina, em particular o funcionamento de um gerenciador de entrada e saída e o de arquivos, foi desenvolvido um simulador que replicasse as operações realizadas pelo sistema operacional nestes gerenciadores. O código em linguagem C se encontra disponível em (?-link do git).

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

##### Login
blablablab usuario cria login blablabla, associado as permissoes

##### open
Esta operação é capaz de abrir um arquivo solicitado. Caso este arquivo não exista, um novo será criado com este mesmo nome. Um exemplo de uso do comando seria:
```
open exercicioSO.txt
```
##### open
Esta operação é capaz de abrir um arquivo solicitado. Caso este arquivo não exista, um novo será criado com este mesmo nome. Um exemplo de uso do comando seria:
```
open exercicioSO.txt
```
Etapas envolvidas nesta operação:
1. Faz uma requisição passando nome do arquivo para a  controladora_do_disco passar o arquivo no HD para a RAM.
2. Controladora_DMA recebe uma requisição para abrir com o endereço lógico "file.txt" 
3. A controladora_DMA envia ao controlador do disco a informação.
4. O controlador do disco, transforma o "file.txt" usando o Directory_Table em um InodeNumber.
5. Tendo o Inodenumber, o controlador do disco usa o Inode_Table para determinar o endereço físico no disco e o tamanho.
6. Com o endereço físico, o controlador do disco transfere o conteúdo (Disk_file_Table) para a  controladora_DMA.
7. A controladora_DMA envia o conteúdo a memória RAM.
8. Enfim tem-se o arquivo na RAM (File_RAM_Table atualizada).

##### delete
Esta operação é capaz de abrir um arquivo solicitado. Caso este arquivo não exista, uma mensagem de erro é impressa ao usuário. Um exemplo de uso do comando seria:
```
delete compprog.txt
```



You can also:
  - Import and save files from GitHub, Dropbox, Google Drive and One Drive
  - Drag and drop markdown and HTML files into Dillinger
  - Export documents as Markdown, HTML and PDF

Markdown is a lightweight markup language based on the formatting conventions that people naturally use in email.  As [John Gruber] writes on the [Markdown site][df1]

> The overriding design goal for Markdown's
> formatting syntax is to make it as readable
> as possible. The idea is that a
> Markdown-formatted document should be
> publishable as-is, as plain text, without
> looking like it's been marked up with tags
> or formatting instructions.

This text you see here is *actually* written in Markdown! To get a feel for Markdown's syntax, type some text into the left window and watch the results in the right.

### Tech

Dillinger uses a number of open source projects to work properly:

* [AngularJS] - HTML enhanced for web apps!
* [Ace Editor] - awesome web-based text editor
* [markdown-it] - Markdown parser done right. Fast and easy to extend.
* [Twitter Bootstrap] - great UI boilerplate for modern web apps
* [node.js] - evented I/O for the backend
* [Express] - fast node.js network app framework [@tjholowaychuk]
* [Gulp] - the streaming build system
* [Breakdance](http://breakdance.io) - HTML to Markdown converter
* [jQuery] - duh

And of course Dillinger itself is open source with a [public repository][dill]
 on GitHub.

### Installation

Dillinger requires [Node.js](https://nodejs.org/) v4+ to run.

Install the dependencies and devDependencies and start the server.

```sh
$ cd dillinger
$ npm install -d
$ node app
```

For production environments...

```sh
$ npm install --production
$ npm run predeploy
$ NODE_ENV=production node app
```

### Plugins

Dillinger is currently extended with the following plugins. Instructions on how to use them in your own application are linked below.

| Plugin | README |
| ------ | ------ |
| Dropbox | [plugins/dropbox/README.md] [PlDb] |
| Github | [plugins/github/README.md] [PlGh] |
| Google Drive | [plugins/googledrive/README.md] [PlGd] |
| OneDrive | [plugins/onedrive/README.md] [PlOd] |
| Medium | [plugins/medium/README.md] [PlMe] |
| Google Analytics | [plugins/googleanalytics/README.md] [PlGa] |


### Development

Want to contribute? Great!

Dillinger uses Gulp + Webpack for fast developing.
Make a change in your file and instantanously see your updates!

Open your favorite Terminal and run these commands.

First Tab:
```sh
$ node app
```

Second Tab:
```sh
$ gulp watch
```

(optional) Third:
```sh
$ karma test
```
#### Building for source
For production release:
```sh
$ gulp build --prod
```
Generating pre-built zip archives for distribution:
```sh
$ gulp build dist --prod
```
### Docker
Dillinger is very easy to install and deploy in a Docker container.

By default, the Docker will expose port 80, so change this within the Dockerfile if necessary. When ready, simply use the Dockerfile to build the image.

```sh
cd dillinger
docker build -t joemccann/dillinger:${package.json.version}
```
This will create the dillinger image and pull in the necessary dependencies. Be sure to swap out `${package.json.version}` with the actual version of Dillinger.

Once done, run the Docker image and map the port to whatever you wish on your host. In this example, we simply map port 8000 of the host to port 80 of the Docker (or whatever port was exposed in the Dockerfile):

```sh
docker run -d -p 8000:8080 --restart="always" <youruser>/dillinger:${package.json.version}
```

Verify the deployment by navigating to your server address in your preferred browser.

```sh
127.0.0.1:8000
```

#### Kubernetes + Google Cloud

See [KUBERNETES.md](https://github.com/joemccann/dillinger/blob/master/KUBERNETES.md)


### Todos

 - Write MOAR Tests
 - Add Night Mode

License
----

MIT


**Free Software, Hell Yeah!**

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


   [dill]: <https://github.com/joemccann/dillinger>
   [git-repo-url]: <https://github.com/joemccann/dillinger.git>
   [john gruber]: <http://daringfireball.net>
   [df1]: <http://daringfireball.net/projects/markdown/>
   [markdown-it]: <https://github.com/markdown-it/markdown-it>
   [Ace Editor]: <http://ace.ajax.org>
   [node.js]: <http://nodejs.org>
   [Twitter Bootstrap]: <http://twitter.github.com/bootstrap/>
   [jQuery]: <http://jquery.com>
   [@tjholowaychuk]: <http://twitter.com/tjholowaychuk>
   [express]: <http://expressjs.com>
   [AngularJS]: <http://angularjs.org>
   [Gulp]: <http://gulpjs.com>

   [PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
   [PlGh]: <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
   [PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
   [PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>
   [PlMe]: <https://github.com/joemccann/dillinger/tree/master/plugins/medium/README.md>
   [PlGa]: <https://github.com/RahulHP/dillinger/blob/master/plugins/googleanalytics/README.md>
