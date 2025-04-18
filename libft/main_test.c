/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:24:52 by mcekici           #+#    #+#             */
/*   Updated: 2024/11/01 14:12:50 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "libft.h"
#include <fcntl.h>
*/
/*test_func1
static char	test_func1(unsigned int num, char c)
{
	return (c + (char)num);
}
*/
/*test_func2
static void	test_func2(unsigned int num, char *c)
{
	*c += num;
}
*/
/*test_func3
static void test_func3(void *content)
{
	content = ft_strdup("42");
}
*/
/*test_func4
static void	*test_func4(void *content)
{
	if (!content)
		return (0);
	return (ft_strdup((char *)content));
}
*/
/*del_func
static void	del_test(void *content)
{
	free(content);
}
*/
/*lst_view
static void	ft_lstview(t_list *iter)
{
	while (iter)
	{
		printf("%s->", (char *)iter->content);
		iter = iter->next;
	}
	printf("NULL\n");
}
*/
/*MAIN_FUNC
int	main(void)
{
	return (0);
}
*/
/*memset
	char	dizi[] = "Merhaba";
	printf("%s\n", (char *)ft_memset((void *)dizi, 'x', 2));
*/
/*memcpy
	char	dizi[] = "Merhaba";
	char	*ptr = (char *)malloc(sizeof(dizi));
	printf("%s\n", (char *)ft_memcpy(ptr, dizi, sizeof(dizi)));
*/
/*memmove
	char	dizi1[30] = "\0\0\0\0\0Merhaba";
	char	dizi2[30] = "Merhaba";
	printf("%s\n", (char *)ft_memmove(dizi1, dizi1 + 5, 7));
	printf("%s\n", (char *)ft_memmove(dizi2 + 2, dizi2, 7));
*/
/*strlcat
	char src1[] = " Dunya";
	char dst1[25] = "Merhaba";
	printf("%d\n", (int)ft_strlcat(dst1, src1, 25));
	char src2[] = " Dunya";
	char dst2[25] = "Merhaba";
	printf("%d\n", (int)strlcat(dst2, src2, 25));
*/
/*strchr
	char metin[] = "Merhaba";
	printf("%s\n", ft_strchr(metin, 'a'));
*/
/*strrchr
	char metin[] = "Merhaba ben kerem";
	printf("%s\n", ft_strrchr(metin, 'a'));
*/
/*strnstr
	printf("%s\n", ft_strnstr("Merhaba ben", "ba", sizeof("Merhaba ben")));
*/
/*atoi	
	printf("%d\n", ft_atoi("   \n24  asd"));
	printf("%d\n", atoi("   \n24  sad"));
*/
/*strdup
	printf("%s\n", ft_strdup("Merhaba"));
*/
/*substr
	printf("%s\n", ft_substr("Merhaba Ben kerem", 7, 7));
*/
/*strjoin
	printf("%s\n", ft_strjoin("Merhaba ben ", "  Kerem"));
*/
/*strtrim
	printf("%s\n", ft_strtrim(",.  Hello World!,,.. ..,", ",. "));
*/
/*split
	char **ptr = ft_split("Merhaba,42,Libft,Yapiyoruz", ',');
	while (*ptr)
	{
		printf("%s\n", *ptr);
		ptr++;
	}
*/
/*itoa
	printf("%s\n", ft_itoa(-234));
	printf("%s\n", ft_itoa(235434));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(0));
*/
/*strmapi
	printf("%s\n", ft_strmapi("abcdefg", test_func1));
*/
/*striteri
	char str[] = "abcdefg";
	printf("%s\n", str);
	ft_striteri(str, test_func2);
	printf("%s\n", str);
*/
/*putchar_fd
	int	fd = open("../Test_code.txt", O_CREAT | O_TRUNC | O_RDWR, 0666);
		// O_CREAT		Eğer dosya yoksa oluştur
		// O_TRUNC		Eğer dosya varsa içeriğini siler
		// O_WRONLY		Write Only Modunda açılyor
		// 0666			Dosya izlinlerini belirleme (umask 000 yapılmalı) 
	
	if (fd == -1)
	{
		ft_putstr_fd("Dosya Acilamadi!\n", 1);
		return (1);
	}
	ft_putchar_fd('g', fd);
	close(fd);
*/
/*struct t_list & lstnew
	t_list lst1;
	lst1.content = "Merhaba 42";
	lst1.next = 0;
	printf("%s\n", lst1.content);
	t_list *lst = ft_lstnew("Echole 42");
	printf("%s\n", lst->content);
	lst->next = &lst1;
	printf("%s\n", lst->next->content);
*/
/*lstadd_front
	t_list	*head = ft_lstnew("Merhaba ben lst1");
	ft_lstadd_front(&head, ft_lstnew("Merhaba ben lst2"));
	ft_lstadd_front(&head, ft_lstnew("Merhaba ben lst3"));
	ft_lstview(head);
*/
/*lstadd_back
	t_list	*head = ft_lstnew("lst1");
	ft_lstadd_back(&head, ft_lstnew("lst2"));
	ft_lstadd_back(&head, ft_lstnew("lst3"));
	ft_lstview(head);
*/
/*lstlast
	t_list	*head = ft_lstnew("lst1");
	head -> next = ft_lstnew("lst2");
	head -> next -> next = ft_lstnew("lst3");
	printf("List Last Member: %s\n", (char *)ft_lstlast(head)->content);
*/
/*lstdelone
	t_list	*head = ft_lstnew(ft_strdup("lst1"));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("lst2")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("lst3")));
	ft_lstview(head);
	t_list	*tmp = head->next->next;
	head->next->next = 0;
	ft_lstdelone(tmp, del_test);
	ft_lstview(head);
*/
/*lstclear
	t_list	*head = ft_lstnew(ft_strdup("lst1"));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("lst2")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("lst3")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("lst4")));
	ft_lstview(head);
	ft_lstclear(&(head->next->next), del_test);
	ft_lstview(head);
*/
/*lstiteri
	t_list	*head = ft_lstnew(ft_strdup("lst1"));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("lst2")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("lst3")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("lst4")));
	ft_lstview(head);
	ft_lstiter(head, test_func3);
	ft_lstview(head);
*/
/*lstmap
	t_list	*head = ft_lstnew(ft_strdup("lst1"));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("lst2")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("lst3")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("lst4")));
	ft_lstview(head);
	printf("%p\n", head->next->next->content);
	t_list	*ptr = ft_lstmap(head, test_func4, del_test);
	ft_lstview(ptr);
	printf("%p\n", ptr->next->next->content);
*/