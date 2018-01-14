/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:47:43 by cammapou          #+#    #+#             */
/*   Updated: 2018/01/09 17:39:23 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 **
 ** • Le premier paramètre est le file descriptor depuis lequel lire.
 **
 ** • Le second paramètre est l’adresse d’un pointeur sur caractère qui servira à stocker
 ** la ligne lue sur le file descriptor.
 ** 
 **	• La valeur de retour peut être 1, 0 ou -1 selon qu’une ligne a été lue, que la lecture est terminée ou bien qu’une erreur est survenue respectivement.
 **
 ** • Votre fonction get_next_line doit renvoyer son resultat sans le ’\n’.
 **
 ** • Un appel en boucle à votre fonction get_next_line permettra donc de lire le texte disponible sur un descripteur de fichier une ligne à la fois jusqu’à la 
 ** fin du texte, quelque soit la taille du texte en question ou d’une de ses lignes.
 **
 ** • Assurez-vous que votre fonction se comporte bien lorsqu’elle lit depuis un fichier, depuis l’entrée standard, depuis une redirection, etc.
 **
 ** • Votre fichier get_next_line.h doit au moins contenir le prototype de la fonction get_next_line et une macro permettant de choisir la taille du buffer de 
 ** lecture de read. Cette valeur sera modifiée en soutenance pour évaluer la robustesse de votre rendu. Cette macro devra impérativement s’appeler BUFF_SIZE.
 ** 
 ** • On considère que get_next_line a un comportement indeterminé si entre deux appels, un même descripteur de fichier désigne deux fichiers différents 
 ** alors que la lecture du premier fichier n’était pas terminée.
 **
 ** • On considère également qu’un appel à la fonction lseek(2) n’aura jamais lieu entre deux appels à get_next_line sur un même descripteur de fichier.
 **
 ** • On considère enfin que get_next_line a un comportement indeterminé́ en cas de lecture dans un fichier binaire. Cependant, si vous le souhaitez, 
 ** vous pouvez rendre ce comportement cohérent.
 **
 ** • Les variables globales sont interdites.
 **
 ** • Les variables statiques sont autorisées.
 **
 ** test des leaks faire une boucle infinie dans le main avant le return et executer le programe avec leaks a.out par exemple.
 ** 
 **	----------------------------------------------------------------------------------------------------------------------------------------
 **
 ** 							MON PROGRAMME GET NEXT LINE 
 **
 **	1. Controler si les variable sont bien initialiser ou qu'il a une valuer dedans, remplissage du buffer avec 0.
 ** 
 ** 2. Je crée un emplacement de memoire dynamique pour le char **line pour permettre de copier buf dans line si l'alllocation echoue ma condition renvois 0.
 ** 
 ** 3. Je crée une boucle pour lire le fichier j'ai déclaré une variable "ret" pour récupérer le nombre d'octet lus.
 ** 
 ** 4. Pendant la lecture j'utilise la fonction "ft_strjoin" pour permetre de copier correctement buf dans line caractere par caractere (faire attention au fuites memoire par la suite 
 ** 	retrouver la tête pour pouvoir la free).
 **	 
 **	5. Je crée une condition dans la boucle de lecture, j'utilise la fonction "ft_strchr" dans le buffer pour permettre a ma boucle de s'arreter a la rencontre
 **	   d'un retour a la ligne je quitte avec "break" .
 **	
 **	6. Je dois récupérer le reste qui a été lus et enregistrer dans ligne et le placé dans une variable static de type char.  
 ** 
 ** 7 .Géré les differentes variation de BUF_SIZE (soucis sur la taille de l'allocation)
 **
 ** 8. extraire le rest de la variable "rest" est le revoyer (?) XXXII-G-2. Comportement interne fgets :
 **
 **	9. ? faire une boucle avec ret ?
 **	  
 ** http://emmanuel-delahaye.developpez.com/tutoriels/c/notes-langage-c/?page=Page6
 **
 */

/*void	ft_allocation_memorie(char *line, static char *rest)
{
}*/

int 	ft_check_valide(char **rest, char *line)
{
	if (!*rest || !*line)
		return (0);
	else
		*rest = ft_strchr(line, '\n') + 1;
		line = *ft_strsplit(line, '\n');
		//**line = ft_strjoin(**line, *rest);
	return (1);
}



int 	ft_len_line(char *line)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(line);
	while (--len > 0)
	{
		if (line[len] == '\n')
			break;
		i++;
	}
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*rest;
	int ret;
	int i;

	i = 0;
	ret = 0;
	if (!line || fd < 0 || BUFF_SIZE < 0 || ret < 0)
		return (-1);
	ft_bzero(buff, BUFF_SIZE);
	*line = ft_strnew(BUFF_SIZE);
	rest = ft_strnew(ft_len_line(*line));
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		*line = ft_strjoin(*line, buff);
		if (ft_strchr(buff, '\n'))
			break;
	}
	if (ft_check_valide(&rest, *line) == 1)
		return (1);
	//rest = ft_strchr(*line, '\n') + 1;
	//*line = *ft_strsplit(*line, '\n');
	//printf("rest = |%s|\n", rest);
	return (0);
}