#ifndef NDN_CONGESTION_TAG_HPP
#define NDN_CONGESTION_TAG_HPP

namespace ndn {

/* used to simulate congestion marks */
/* CongestionTag's congestion mark is set to true in case of congestion */
/* NFD will get this tag and react to congestion mark */

class CongestionTag: public Tag
{
public:
	static constexpr int
	getTypeId()
	{
		return 0xf725e224; // md5("NDNCongestionTag")[0:8]
	}

	CongestionTag()
		: m_congMark(false)
	{

	}

	CongestionTag(bool congMark)
		: m_congMark(congMark)
	{

	}

	void setCongMark(bool m)
	{
		m_congMark = m;
	}

	bool getCongMark()
	{
		return m_congMark;
	}

private:
	bool m_congMark;
};
}

#endif