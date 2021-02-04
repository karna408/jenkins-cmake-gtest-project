#ifndef ZF_SAMPLE_ADDITION_HPP
#define ZF_SAMPLE_ADDITION_HPP

/*!
 *  @addtogroup zf::sample
 *  
 */

namespace zf {
namespace sample {
/**
 * @brief Addition
 *
 */
class Addition {        
public:
    /**
     * @brief  Addition constructor.
     *
     * @param id: identification number 
     */
    Addition(int id = 0);

    /**
     * @brief Addition destructor.
     *
     */
    ~Addition();

    /**
     * @brief  Addition of two integers
     *
     * @param a: first integer
     * @param b: second integer
     * @return Sum of a and b
     */
    int add(int a1, int a2);

    /**
     * @brief  Addition of one integer and the ID
     *
     * @param val: integer to add
     * @return Sum of val and internal id
     */
    int addID(int val);

    /**
     * @brief  Addition of one integer and 1
     *
     * @param val: integer to add
     * @return Sum of val and 1
     */
    int addOne(int val);

    /**
     * @brief  Addition of one integer and 2
     *
     * @param val: integer to add
     * @return Sum of val and 2
     */
    int addTwo(int val);

private:
    /// Internal identification number
    int id_;
};
} // namespace sample
} // namespace zf

#endif // ZF_SAMPLE_ADDITION_HPP