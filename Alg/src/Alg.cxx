#include "Alg.h"

Alg::Alg(const std::string& name, ISvcLocator* pSvcLocator)
: AthHistogramAlgorithm(name, pSvcLocator) { m_hist = nullptr; }

Alg::~Alg() { }

StatusCode Alg::initialize()
{
    //letter at end of TH1 indicated variable type (D doublem F float etc)
    m_hist = new TH1D("Simulation", "Data Test", 100, 0, 1); //first string titel, second data
    ATH_CHECK(histSvc()->regHist("/HIST/myhist", m_hist));
    ATH_CHECK( m_mcEventKey.initialize() );
    ATH_CHECK( m_faserSiHitCol.initialize() );
    ATH_MSG_INFO( "Using event colletion with key " << m_mcEventKey.key());
//    ATH_MSG_INFO( "Using Faser SiHit Collection with key " << m_faserSiHitCol.key());
    return StatusCode::SUCCESS;
}

StatusCode Alg::execute()
{
    SG::ReadHandle<McEventCollection> h_mcEvent(m_mcEventKey);
    ATH_MSG_INFO("Read McEventContainer with " << h_mcEvent->size() << " event");
    SG::ReadHandle<FaserSiHitCollection> h_siHitEvent(m_faserSiHitCol);
    ATH_MSG_INFO("Read FaserSiHitCollection with " << h_siHitEvent->size() << " event");
    if (h_mcEvent->size() == 0) return StatusCode::FAILURE;
    const HepMC::GenEvent* ev = (*h_mcEvent)[0];
    if (ev == nullptr) 
    {
        ATH_MSG_FATAL("Event pointer is null");
        return StatusCode::FAILURE;
    }
    ATH_MSG_INFO("Event contains " << ev->particles_size() << " particles" );

    if (h_siHitEvent->size() == 0) return StatusCode::SUCCESS;
    (*h_siHitEvent)[0].print();
/*    const FaserSiHit* siHit = &(*h_siHitEvent)[0];
    if( siHit == nullptr)
    {
        ATH_MSG_FATAL("SiHit pointer is null");
        return StatusCode::FAILURE;
    }
    siHit->print();*/

    //testing histogram stuff
    m_hist->Fill( (*h_siHitEvent)[0].energyLoss());


    return StatusCode::SUCCESS;
}

StatusCode Alg::finalize()
{
    return StatusCode::SUCCESS;
}