/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:05:32 by schuah            #+#    #+#             */
/*   Updated: 2022/12/12 22:17:45 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

namespace ft
{
	/* Definitions */
	template <class T> class	rbt_end_node;
	template <class T> class	rbt_node;

	/* Helper struct to define aliases */
	template <class T>
	struct	rbt_node_types
	{
		typedef	rbt_end_node<T>		end_node_type;
		typedef	end_node_type*		end_node_pointer;
		typedef	rbt_node<T>			node_type;
		typedef	node_type*			node_pointer;
	};

	/* End node class of RBTree */
	template <class T>
	class	rbt_end_node
	{
		public:
			/* Member types */
			typedef typename rbt_node_types<T>::node_pointer	node_pointer;

            /* Public member objects */
			node_pointer	_left;

			/* Orthodox canonical form */
			rbt_end_node() : _left(NULL) {};
			rbt_end_node(const rbt_end_node& other) : _left(other._left) {};
			~rbt_end_node() {};
			rbt_end_node&	operator=(const rbt_end_node& other)
			{
				if (this == &other)
					return (*this);
				this->_left = other._left;
				return (*this);
			}
	};

	/* Node class of RBTree */
	template <class T>
	class	rbt_node : public rbt_node_types<T>::end_node_type
	{
		public:
			/* Member types */
			typedef typename rbt_node_types<T>::end_node_pointer		end_node_pointer;
			typedef typename rbt_node_types<T>::node_pointer			node_pointer;


            /* Public member objects */
			node_pointer		_right;
			end_node_pointer	_parent;
			bool				_black;
			T					_value;

			/* Orthodox canonical form */
			rbt_node() : _right(NULL), _parent(NULL), _black(false), _value(NULL) {};
			rbt_node(const rbt_node& other) : _right(other._right), _parent(other._parent), _black(other._black), _value(other._value) {};
			~rbt_node() {};
			rbt_node&	operator=(const rbt_node& other)
			{
				if (this == &other)
					return (*this);
				this->_right = other._right;
				this->_parent = other._parent;
				this->_black = other._black;
				this->_value = other._value;
			}

			/* Getter and setter function for parent of node */
			node_pointer	get_parent() const { return (static_cast<node_pointer>(this->_parent)); }
			void	set_parent(node_pointer parent) { this->_parent = static_cast<end_node_pointer>(parent); }
	};
}

#endif
