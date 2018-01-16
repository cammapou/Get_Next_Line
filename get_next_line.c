/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:47:43 by cammapou          #+#    #+#             */
/*   Updated: 2018/01/15 16:31:36 by cammapou         ###   ########.fr       */
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
 ** 4. Pendant la lecture j'utilise la fonction "ft_strjoin" pour permetre de copier correctement buf dans line (faire attention au fuites memoire par la suite 
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

#include "get_next_line.h"

int			ft_len(char *str, char c)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void		ft_sub(char **line, char **str)
{
	char	*s;

	s = NULL;
	*line = ft_strsub(*str, 0, ft_len(*str, '\n'));
	s = ft_strsub(*str, ft_len(*str, '\n') + 1,
		ft_strlen(&str[0][ft_len(*str, '\n')]));
	ft_strdel(str);
	*str = s;
}

int			get_next_line(const int fd, char **line)
{
	char					buff[BUFF_SIZE + 1];
	static	char			*str[256];
	char					*tmp;
	int						ret;

	ret = 0;
	if (!line || fd < 0 || BUFF_SIZE < 0 || read(fd, "", 0))
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(1);
	while (!(ft_strchr(str[fd], '\n')))
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == 0)
			break ;
		buff[ret] = '\0';
		tmp = ft_strjoin(str[fd], buff);
		ft_strdel(&str[fd]);
		str[fd] = tmp;
	}
	if (ft_strlen(str[fd]) == 0)
		return (0);
	ft_sub(line, &str[fd]);
	return (1);
}