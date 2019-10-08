# Gerenciamento de Biblioteca
## User Stories
### User Story 01:
<p>Como um leitor da biblioteca eu gostaria de buscar um livro para achar sua localização física.</p>
<p><b>Critérios de aceitação:</b></p>
<p>Busca de um livro por título, autor ou categoria;</p>
<p>Busca deve retornar em qual prateleira de qual estante está o livro, ou se está alugado;</p>
<p>Busca deve retornar todas as informações do livro (título, editora, edição, autor, idioma e categoria);</p>
<p>Alugar um livro deve alterar a localização dele de forma que identifique que está locado e por quem ele foi locado;</p>

### User Story 02:
<p>Como um leitor da biblioteca eu gostaria de saber onde é o lugar devido para se guardar um determinado livro,
para que eu mantenha a biblioteca organizada.</p>
<p><b>Critérios de aceitação:</b></p>
<p>Opção de devolver o livro retorna o local que ele deve ser guardado;</p>
<p>Para devolver um livro pode se buscá-lo por ID, título ou autor, além de poder apenas checar na lista de todos
os livros alugados no momento pelo leitor fazendo a devolução;</p>
<p>A lista de busca deve retornar apenas livros alugados;</p>
<p>Ao devolver um livro, sua localização deve ser alterada para a estante e prateleira que ele está, e seu status 
deve mudar de alugado para disponível;</p>

### User Story 03:
<p>Como um organizador da biblioteca eu gostaria de catalogar mais um livro para que ele seja alocado na biblioteca corretamente.</p>
<p><b>Critérios de aceitação:</b></p>
<p>Para entrar com um livro no sistema tem que se fornecer Título, Autor, Edição, Editora, Idioma e Categoria;</p>
<p>Uma ID deve ser gerada para aquela cópia do livro;</p>
<p>O local apontado pelo sistema para se guardar o livro deve estar disponível;</p>

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
    <td>Nome</td>
    <td>Leitor</td>
  </tr>
  <tr>
    <td>ID de Usuário</td>
    <td>Organizador</td>
  </tr>
  <tr>
    <td>Permissão Organizador</td>
    <td> </td>
  </tr>
</table>

<table>
  <tr>
    <th>Classe:  Leitor</th>
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
    <td>ID de Usuário</td>
    <td>Estante </td>
  </tr>
  <tr>
    <td>Livros Alugados </td>
    <td>Organizador </td>  
  </tr>
  <tr>
    <td>Alugar Livro </td>
    <td>Categoria </td>
  </tr>
  <tr>
    <td>Devolver Livro </td>
    <td>Prateleira </td>
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
    <td>ID de Usuário </td>
    <td>Estante </td>
  </tr>
  <tr>
    <td>Registrar Usuário </td>
    <td>Categoria </td>
  </tr>
  <tr>
    <td>Registrar Novo Livro </td>
    <td>Prateleira </td>
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
    <td>Estante </td>
  </tr>
  <tr>
    <td>Autor </td>
    <td>Leitor </td>
  </tr>
  <tr>
    <td>Editora </td>
    <td>Organizador </td>
  </tr>
  <tr>
    <td>Edição </td>
    <td>Prateleira </td>
  </tr>
  <tr>
    <td>Categoria </td>
    <td>Categoria </td>
  </tr>
  <tr>
    <td>Idioma </td>
    <td> </td>
  </tr>
  <tr>
    <td>ID de Livro </td>
    <td> </td>
  
  </tr>
  <tr>
    <td>Status de Aluguel </td>
    <td> </td>
  
  </tr>
  <tr>
    <td>Alugado Por </td>
    <td> </td>
  </tr>
  <tr>
    <td>Localização </td>
    <td> </td>
  </tr>
</table>


<table>
  <tr>
    <th>Classe:  Estante </th>
    <th> </th>
  </tr>
   <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>ID de Estante </td>
    <td>Prateleira </td>
  </tr>
  <tr>
    <td>Quarto </td>
    <td>Categoria </td>
  </tr>
  <tr>
    <td>Prateleiras </td>
    <td> </td>
  </tr>
  <tr>
    <td>Categorias Comportadas </td>
    <td> </td>
  </tr>
</table>


<table>
  <tr>
    <th>Classe: Prateleira </th>
    <th> </th> 
  </tr>
   <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>ID de Prateleira </td>
    <td>Estante </td>
  </tr>
  <tr>
    <td>Estante </td>
    <td>Leitor </td>
  </tr>
  <tr>
    <td>Livros da Prateleira </td>
    <td>Organizador </td>  
  </tr>
  <tr>
    <td>Espaço Vazio </td>
    <td>Livro </td>
  </tr>
  <tr>
    <td>Categorias Comportadas </td>
    <td>Categoria </td>
  </tr>
  <tr>
    <td>Alocar Novo Livro </td>
    <td> </td>
  </tr>
</table>


<table>
  <tr>
   <th>Classe:  Categoria</th>
   <th> </th>
  </tr>
   <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>Nome </td>
    <td>Estante </td>
  </tr>
  <tr>
    <td>Localização nas Prateleiras </td>
    <td>Prateleira </td>
  </tr>
  <tr>
    <td>Livros </td>
    <td>Livro </td>
  </tr>
  <tr>
    <td>Categoria Mãe </td>
    <td> </td>
  </tr>
  <tr>
    <td>Categorias Filhas </td>
    <td> </td>
  </tr>
  <tr>
    <td>Gerar nova filha </td>
    <td> </td> 
  </tr>
</table>
