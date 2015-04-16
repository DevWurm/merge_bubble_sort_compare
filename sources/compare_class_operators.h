/*
	 * License

	 * Copyright 2015 DevWurm

	 * This file is part of merge_sort_bubble_sort_compare.

	 *  merge_sort_bubble_sort_compare is free software: you can redistribute it and/or modify
	    it under the terms of the GNU General Public License as published by
	    the Free Software Foundation, either version 3 of the License, or
	    (at your option) any later version.

	    merge_sort_bubble_sort_compare is distributed in the hope that it will be useful,
	    but WITHOUT ANY WARRANTY; without even the implied warranty of
	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	    GNU General Public License for more details.

	    You should have received a copy of the GNU General Public License
	    along with merge_sort_bubble_sort_compare.  If not, see <http://www.gnu.org/licenses/>.

	    Diese Datei ist Teil von merge_sort_bubble_sort_compare.

	    merge_sort_bubble_sort_compare ist Freie Software: Sie können es unter den Bedingungen
	    der GNU General Public License, wie von der Free Software Foundation,
	    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder späteren
	    veröffentlichten Version, weiterverbreiten und/oder modifizieren.

	    merge_sort_bubble_sort_compare wird in der Hoffnung, dass es nützlich sein wird, aber
	    OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite
	    Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
	    Siehe die GNU General Public License für weitere Details.

	    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
	    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
*/

#include "../headers/compare_class.h"
#include "../libcsv/libcsv.h"
#include <istream>
#include <deque>

using std::deque;
using std::istream;
using csv::csv_creator;
using csv::csv_parser;
using csv::csv_handler;

namespace compare {
	template<typename T>
	compare_class<T>& operator >>(csv_parser<T>& input, compare_class<T>& target) {
		input >> target.data;
		return target;
	}

	template<typename T>
	csv_creator<T>& compare_class<T>::operator >>(csv_creator<T>& target) {
		data >> target;
		return target;
	}

	template<typename T>
	istream& operator >>(istream& input, compare_class<T>& target) {
		csv_handler<T> temp_handler;
		input >> temp_handler >> target.data;
		return input;
	}

	template<typename T>
	ostream& operator <<(ostream& output, compare_class<T>& source) {
		csv_handler<T> temp_handler;
		source.data >> temp_handler >> output;
		return output;
	}
}