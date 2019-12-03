# Gerenciamento de Biblioteca
## User Stories
### User Story 01:
<p>Como um leitor da biblioteca eu gostaria de buscar um livro para achar sua localização física.</p>
<p><b>Critérios de aceitação:</b></p>
<p>Busca de um livro por título;</p>
<p>Busca deve retornar em qual estante e qual quarto está o livro, ou se está alugado;</p>
<p>Busca deve retornar todas as informações do livro (título, autor);</p>
<p>Alugar um livro deve alterar a situação dele de forma que identifique que está locado e por quem ele foi locado;</p>

### User Story 02:
<p>Como um usuário Premium da biblioteca eu gostaria de locar quantos livros eu quiser.</p>
<p><b>Critérios de aceitação:</b></p>
<p>Locar número ilimitado de livros sem gerar erros;</p>

### User Story 03:
<p>Como um usuário Premium da biblioteca eu gostaria de ter acessos a livros, mesmo que limitado, sem ter que pagar pela minha conta.</p>
<p><b>Critérios de aceitação:</b></p>
<p>Locar número limitado de livros sem gerar erros;</p>
<p>Não permitir locação de livros acima do limite;</p>


### User Story 04:
<p>Como um organizador da biblioteca eu gostaria de registrar um novo leitor para que ele possa utilizar a biblioteca;</p>
<p><b>Critérios de aceitação:</b></p> 
<p>O novo usuário tem que ter nome;</p>
<p>Uma ID de usuário deve ser gerada;</p>
<p>Deve-se informar ao sistema se o usuário pode também fazer o papel de organizador ou só de leitor;</p>

## Cartões CRC:

<table>
  <tr>
    <th>Classe:  Usuário</th>
    <th> </th>
  </tr>
  <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>Username</td>
    <td>Free</td>
  </tr>
  <tr>
    <td>Nome</td>
    <td>Organizador</td>
  </tr>
  <tr>
    <td>Lista de Livros Alugados</td>
    <td>Premium</td>
  </tr>
   <tr>
    <td>Lista de Livros Alugados</td>
    <td>Livro</td>
  </tr>
</table>

<table>
  <tr>
    <th>Classe:  Free</th>
    <th> </th>
  </tr>
   <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>Nome </td>
    <td>Livro </td>
  </tr>
  <tr>
    <td>Username</td>
    <td>Organizador </td>
  </tr>
  <tr>
    <td>Livros Alugados </td>
    <td> </td>  
  </tr>
  <tr>
    <td>Alugar Livro </td>
    <td> </td>
  </tr>
  <tr>
    <td>Devolver Livro </td>
    <td> </td>
  </tr>
</table>

<table>
  <tr>
    <th>Classe:  Premium</th>
    <th> </th>
  </tr>
   <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>Nome </td>
    <td>Livro </td>
  </tr>
  <tr>
    <td>Username</td>
    <td>Organizador </td>
  </tr>
  <tr>
    <td>Livros Alugados </td>
    <td> </td>  
  </tr>
  <tr>
    <td>Alugar Livro </td>
    <td> </td>
  </tr>
  <tr>
    <td>Devolver Livro </td>
    <td> </td>
  </tr>
</table>

<table>
  <tr>
    <th>Classe:  Organizador</th>
    <th> </th>
  </tr>
   <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>Nome </td>
    <td>Livro </td> 
  </tr>
  <tr>
    <td>Username </td>
    <td> </td>
  </tr>
  <tr>
    <td>Registrar Usuário </td>
    <td> </td>
  </tr>
</table>
<table>
  <tr>
    <th>Classe:  Livro</th>
    <th> </th>
  </tr>
   <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>Título </td>
    <td>Premium </td>
  </tr>
  <tr>
    <td>Autor </td>
    <td>Free</td>
  </tr>
  <tr>
    <td>Localização </td>
    <td>Organizador </td>
  </tr>
  <tr>
    <td>Locado Por</td>
    <td> </td>
  </tr>
</table>

## Implementação
### Usuários
<p>Nesta biblioteca existem diferentes tipos de usuários: Organizadores, que além de alugar livros também cadastram outros usuários, Premium, que podem alugar quantos livros quiserem e Free, que tem um limite de locação de três livros. Para a implementação desses diferentes tipos foi criada uma classa mãe, Usuário, e as demais categorias foram colocadas como classes filhas.</p>

<h4> Classe Usuário </h4>
<p>É a classe mãe de todos os tipos de usuário, utilizada para manter em um só lugar os atributos e as funções comuns a todos os outros tipos de usuários</p>

<p><b>Atributos</b></p>
<p>username: uma string que contém o username do usuário</p>
<p>nome: uma string que contém o nome do usuário</p>
<p>livros_alugados: um vetor de strings que contém os livros que o usuário tem consigo</p>

<p><b>Métodos</b></p>
<p>Construtores que recebe tanto nenhum parâmetro, como de parâmetro todos os atributos</p>
<p>Destrutor default </p>
<p>getters e setters para todos os atributos</p>
<p>fazerLogin(std::string username): Método virtual puro implementado nas classes filhas</p>
<p>fazerLogin(std::string username, std::string filepath): Método que busca o usuário pelo username na base de dados passada pelo filepath, cada tipo de usuário tem um arquivo diferente como base de dados, e atualiza o valor de seus atributos dado o resultado da busca. Essa função é chamada dentro da implementação de fazerLogin(std::string username) de cada uma das classes filhas passando o filepath correspondente a base de dados daquela classe</p>
<p>alugarLivro(Livro livro): Método virtual puro implementado nas classes filhas</p>
<p>devolverLivro(Livro livro): Método virtual puro implementado nas classes filhas</p>

<h4> Classe Premium </h4>
<p>É a classe de usuários que pagaram por uma assinatura, podendo assim alugar uma quantidade ilimitada de livros</p>

<p><b>Atributos</b></p>
<p>Apenas os herdados da classe mãe</p>

<p><b>Métodos</b></p>
<p>Construtores que recebe tanto nenhum parâmetro, como de parâmetro todos os atributos</p>
<p>Destrutor default </p>
<p>fazerLogin(std::string username): Override de método virtual da classe mãe, passa o username e o lugar do arquivo que contém a base de dados dos usuários premium para a função fazerLogin(std::string username, std::string filepath) implementada na classe mãe</p>
<p>alugarLivro(Livro livro): Override de método virtual da classe mãe, busca o livro na base de dados e, caso ele não esteja alugado, aluga ele para o usuário, mudando tanto o atributo livros_alugados, quanto nas bases de dados de livros e de usuários premium</p>
<p>devolverLivro(Livro livro): Override de método virtual da classe mãe, retira o livro tanto do atributo livros_alugados, quanto nas bases de dados de livros e de usuários premium</p>
