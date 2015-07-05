// ==========================================================================
// Dedmonwakeen's Raid DPS/TPS Simulator.
// Send questions to natehieter@gmail.com
// ==========================================================================

#include "simulationcraft.hpp"

using namespace hotfix;

// ==========================================================================
// Spell Data
// ==========================================================================

spell_data_nil_t spell_data_nil_t::singleton;

spell_data_not_found_t spell_data_not_found_t::singleton;

// spell_data_t::override ===================================================

bool spell_data_t::override_field( const std::string& field, double value )
{
  if ( util::str_compare_ci( field, "prj_speed" ) )
    _prj_speed = value;
  else if ( util::str_compare_ci( field, "school" ) )
    _school = ( unsigned ) value;
  else if ( util::str_compare_ci( field, "scaling_class" ) )
    _scaling_type = ( int ) value;
  else if ( util::str_compare_ci( field, "spell_level" ) )
    _spell_level = ( unsigned ) value;
  else if ( util::str_compare_ci( field, "max_level" ) )
    _max_level = ( unsigned ) value;
  else if ( util::str_compare_ci( field, "min_range" ) )
    _min_range = value;
  else if ( util::str_compare_ci( field, "max_range" ) )
    _max_range = value;
  else if ( util::str_compare_ci( field, "cooldown" ) )
    _cooldown = ( unsigned ) value;
  else if ( util::str_compare_ci( field, "internal_cooldown" ) )
    _internal_cooldown = ( unsigned ) value;
  else if ( util::str_compare_ci( field, "gcd" ) )
    _gcd = ( unsigned ) value;
  else if ( util::str_compare_ci( field, "duration" ) )
    _duration = ( unsigned ) value;
  else if ( util::str_compare_ci( field, "rune_cost" ) )
    _rune_cost = ( unsigned ) value;
  else if ( util::str_compare_ci( field, "runic_power_gain" ) )
    _runic_power_gain = ( unsigned ) value;
  else if ( util::str_compare_ci( field, "max_stack" ) )
    _max_stack = ( unsigned ) value;
  else if ( util::str_compare_ci( field, "proc_chance" ) )
    _proc_chance = ( unsigned ) value;
  else if ( util::str_compare_ci( field, "proc_charges" ) )
    _proc_charges = ( unsigned ) value;
  else if ( util::str_compare_ci( field, "cast_min" ) )
    _cast_min = ( int ) value;
  else if ( util::str_compare_ci( field, "cast_max" ) )
    _cast_max = ( int ) value;
  else if ( util::str_compare_ci( field, "rppm" ) )
    _rppm = value;
  else
    return false;
  return true;
}

double spell_data_t::get_field( const std::string& field ) const
{
  if ( util::str_compare_ci( field, "prj_speed" ) )
    return _prj_speed;
  else if ( util::str_compare_ci( field, "school" ) )
    return static_cast<double>( _school );
  else if ( util::str_compare_ci( field, "scaling_class" ) )
    return static_cast<double>( _scaling_type );
  else if ( util::str_compare_ci( field, "spell_level" ) )
    return static_cast<double>( _spell_level );
  else if ( util::str_compare_ci( field, "max_level" ) )
    return static_cast<double>( _max_level );
  else if ( util::str_compare_ci( field, "min_range" ) )
    return _min_range;
  else if ( util::str_compare_ci( field, "max_range" ) )
    return _max_range;
  else if ( util::str_compare_ci( field, "cooldown" ) )
    return static_cast<double>( _cooldown );
  else if ( util::str_compare_ci( field, "internal_cooldown" ) )
    return static_cast<double>( _internal_cooldown );
  else if ( util::str_compare_ci( field, "gcd" ) )
    return static_cast<double>( _gcd );
  else if ( util::str_compare_ci( field, "duration" ) )
    return static_cast<double>( _duration );
  else if ( util::str_compare_ci( field, "rune_cost" ) )
    return static_cast<double>( _rune_cost );
  else if ( util::str_compare_ci( field, "runic_power_gain" ) )
    return static_cast<double>( _runic_power_gain );
  else if ( util::str_compare_ci( field, "max_stack" ) )
    return static_cast<double>( _max_stack );
  else if ( util::str_compare_ci( field, "proc_chance" ) )
    return static_cast<double>( _proc_chance );
  else if ( util::str_compare_ci( field, "proc_charges" ) )
    return static_cast<double>( _proc_charges );
  else if ( util::str_compare_ci( field, "cast_min" ) )
    return static_cast<double>( _cast_min );
  else if ( util::str_compare_ci( field, "cast_max" ) )
    return static_cast<double>( _cast_max );
  else if ( util::str_compare_ci( field, "rppm" ) )
    return _rppm;

  return -std::numeric_limits<double>::max();
}

// ==========================================================================
// Spell Effect Data
// ==========================================================================

spelleffect_data_nil_t spelleffect_data_nil_t::singleton;

bool spelleffect_data_t::override_field( const std::string& field, double value )
{
  if ( util::str_compare_ci( field, "average" ) )
    _m_avg = value;
  else if ( util::str_compare_ci( field, "delta" ) )
    _m_delta = value;
  else if ( util::str_compare_ci( field, "bonus" ) )
    _m_unk = value;
  else if ( util::str_compare_ci( field, "sp_coefficient" ) )
    _sp_coeff = value;
  else if ( util::str_compare_ci( field, "ap_coefficient" ) )
    _ap_coeff = value;
  else if ( util::str_compare_ci( field, "period" ) )
    _amplitude = value;
  else if ( util::str_compare_ci( field, "base_value" ) )
    _base_value = ( int ) value;
  else if ( util::str_compare_ci( field, "misc_value1" ) )
    _misc_value = ( int ) value;
  else if ( util::str_compare_ci( field, "misc_value2" ) )
    _misc_value_2 = ( int ) value;
  else if ( util::str_compare_ci( field, "chain_multiplier" ) )
    _m_chain = value;
  else if ( util::str_compare_ci( field, "points_per_combo_points" ) )
    _pp_combo_points = value;
  else if ( util::str_compare_ci( field, "points_per_level" ) )
    _real_ppl = value;
  else if ( util::str_compare_ci( field, "die_sides" ) )
    _die_sides = ( int ) value;
  else
    return false;
  return true;
}

double spelleffect_data_t::get_field( const std::string& field ) const
{
  if ( util::str_compare_ci( field, "average" ) )
    return _m_avg;
  else if ( util::str_compare_ci( field, "delta" ) )
    return _m_delta;
  else if ( util::str_compare_ci( field, "bonus" ) )
    return _m_unk;
  else if ( util::str_compare_ci( field, "sp_coefficient" ) )
    return _sp_coeff;
  else if ( util::str_compare_ci( field, "ap_coefficient" ) )
    return _ap_coeff;
  else if ( util::str_compare_ci( field, "period" ) )
    return _amplitude;
  else if ( util::str_compare_ci( field, "base_value" ) )
    return static_cast<double>( _base_value );
  else if ( util::str_compare_ci( field, "misc_value1" ) )
    return static_cast<double>( _misc_value );
  else if ( util::str_compare_ci( field, "misc_value2" ) )
    return static_cast<double>( _misc_value_2 );
  else if ( util::str_compare_ci( field, "chain_multiplier" ) )
    return _m_chain;
  else if ( util::str_compare_ci( field, "points_per_combo_points" ) )
    return _pp_combo_points;
  else if ( util::str_compare_ci( field, "points_per_level" ) )
    return _real_ppl;
  else if ( util::str_compare_ci( field, "die_sides" ) )
    return static_cast<double>( _die_sides );

  return -std::numeric_limits<double>::max();
}


// ==========================================================================
// Spell Power Data
// ==========================================================================

spellpower_data_nil_t spellpower_data_nil_t::singleton;

// ==========================================================================
// Talent Data
// ==========================================================================

talent_data_nil_t talent_data_nil_t::singleton;

namespace hotfix
{
static auto_dispose< std::vector< hotfix_entry_t* > > hotfixes_;
static custom_dbc_data_t hotfix_db_;
}

// Very simple comparator, just checks for some equality in the data. There's no need for fanciful
// stuff here.
struct hotfix_comparator_t
{
  const std::string& tag, &note;

  hotfix_comparator_t( const std::string& t, const std::string& n ) :
    tag( t ), note( n )
  { }

  bool operator()( const hotfix_entry_t* other )
  { return tag == other -> tag_ && note == other -> note_;  }
};

struct hotfix_sorter_t
{
  bool operator()( const hotfix_entry_t* l, const hotfix_entry_t* r )
  {
    return l -> tag_ < r -> tag_;
  }
};

bool hotfix::register_hotfix( const std::string& tag,
                              const std::string& note,
                              unsigned           flags )
{
  if ( std::find_if( hotfixes_.begin(), hotfixes_.end(), hotfix_comparator_t( tag, note ) ) !=
       hotfixes_.end() )
  {
    return false;
  }

  hotfixes_.push_back( new hotfix_entry_t( tag, note, flags ) );

  return true;
}

void hotfix::apply()
{
  for ( size_t i = 0; i < hotfixes_.size(); ++i )
  {
    hotfixes_[ i ] -> apply();
  }
}

// Return a hotfixed spell if available, otherwise return the original dbc-based spell
const spell_data_t* hotfix::find_spell( const spell_data_t* dbc_spell, bool ptr )
{
  if ( const spell_data_t* hotfixed_spell = hotfix_db_.find_spell( dbc_spell -> id(), ptr ) )
  {
    return hotfixed_spell;
  }
  return dbc_spell;
}

const spelleffect_data_t* hotfix::find_effect( const spelleffect_data_t* dbc_effect, bool ptr )
{
  if ( const spelleffect_data_t* hotfixed_effect = hotfix_db_.find_effect( dbc_effect -> id(), ptr ) )
  {
    return hotfixed_effect;
  }
  return dbc_effect;
}

spell_hotfix_entry_t& hotfix::register_spell( const std::string& tag,
                                              const std::string& note,
                                              unsigned           spell_id,
                                              unsigned           flags )
{
  std::vector<hotfix_entry_t*>::iterator i = std::find_if( hotfixes_.begin(),
      hotfixes_.end(), hotfix_comparator_t( tag, note ) );
  if ( i !=  hotfixes_.end() )
  {
    return *static_cast<spell_hotfix_entry_t*>( *i );
  }

  spell_hotfix_entry_t* entry = new spell_hotfix_entry_t( tag, spell_id, note, flags );
  hotfixes_.push_back( entry );

  std::sort( hotfixes_.begin(), hotfixes_.end(), hotfix_sorter_t() );

  return *entry;
}

effect_hotfix_entry_t& hotfix::register_effect( const std::string& tag,
                                                const std::string& note,
                                                unsigned           effect_id,
                                                unsigned           flags )
{
  std::vector<hotfix_entry_t*>::iterator i = std::find_if( hotfixes_.begin(),
      hotfixes_.end(), hotfix_comparator_t( tag, note ) );
  if ( i !=  hotfixes_.end() )
  {
    return *static_cast<effect_hotfix_entry_t*>( *i );
  }

  effect_hotfix_entry_t* entry = new effect_hotfix_entry_t( tag, effect_id, note, flags );
  hotfixes_.push_back( entry );

  std::sort( hotfixes_.begin(), hotfixes_.end(), hotfix_sorter_t() );

  return *entry;
}

std::string hotfix::to_str()
{
  std::stringstream s;
  for ( size_t i = 0; i < hotfixes_.size(); ++i )
  {
    s << hotfixes_[ hotfixes_.size() - 1 - i ] -> to_str() << std::endl;
  }

  return s.str();
}

std::vector<const hotfix_entry_t*> hotfix::hotfix_entries()
{
  std::vector<const hotfix_entry_t*> data;
  for ( size_t i = 0; i < hotfixes_.size(); ++i )
  {
    data.push_back( hotfixes_[ i ] );
  }

  return data;
}

template<typename T>
static void do_hotfix( dbc_hotfix_entry_t* e, T* dbc_data )
{
  switch ( e -> operation_ )
  {
    case HOTFIX_SET:
      dbc_data -> override_field( e -> field_name_, e -> modifier_ );
      break;
    case HOTFIX_ADD:
      dbc_data -> override_field( e -> field_name_, e -> dbc_value_ + e -> modifier_ );
      break;
    case HOTFIX_MUL:
      dbc_data -> override_field( e -> field_name_, e -> dbc_value_ * e -> modifier_ );
      break;
    case HOTFIX_DIV:
      dbc_data -> override_field( e -> field_name_, e -> dbc_value_ / e -> modifier_ );
      break;
    default:
      break;
  }

  e -> hotfix_value_ = dbc_data -> get_field( e -> field_name_ );
}

std::string hotfix_entry_t::to_str() const
{
  std::stringstream s;
  s << "[" << tag_.substr( 0, 10 ) << "] " << note_;

  return s.str();
}

std::string spell_hotfix_entry_t::to_str() const
{
  std::stringstream s;
  s << hotfix_entry_t::to_str();
  s << std::endl;

  const spell_data_t* spell = hotfix_db_.find_spell( id_, false );
  s << "             ";
  s << "Spell: " << spell -> name_cstr();
  s << " | Field: " << field_name_;
  s << " | Hotfix Value: " << hotfix_value_;
  s << " | DBC Value: " << dbc_value_;
  if ( orig_value_ != -std::numeric_limits<double>::max() &&
       util::round( orig_value_, 6 ) != util::round( dbc_value_, 6 ) )
  {
    s << " [verification fail]";
  }

  return s.str();
}

std::string effect_hotfix_entry_t::to_str() const
{
  std::stringstream s;
  s << hotfix_entry_t::to_str();
  s << std::endl;

  const spelleffect_data_t* e = hotfix_db_.find_effect( id_, false );
  s << "             ";
  s << "Spell: " << e -> spell() -> name_cstr();
  s << " effect#" << ( e -> index() + 1 );
  s << " | Field: " << field_name_;
  s << " | Hotfix Value: " << hotfix_value_;
  s << " | DBC Value: " << dbc_value_;
  if ( orig_value_ != -std::numeric_limits<double>::max() &&
       util::round( orig_value_, 6 ) != util::round( dbc_value_, 6 ) )
  {
    s << " [verification fail]";
  }

  return s.str();
}

void spell_hotfix_entry_t::apply_hotfix( bool ptr )
{
  spell_data_t* s = hotfix_db_.clone_spell( id_, ptr );

  // Record original DBC value before overwriting it
  dbc_value_ = s -> get_field( field_name_ );

  if ( orig_value_ != -std::numeric_limits<double>::max() &&
       util::round( orig_value_, 6 ) != util::round( dbc_value_, 6 ) )
  {
    std::cerr << "[" << tag_ << "]: Hotfix \"" << note_ << "\" for spell \"" << s -> name_cstr() <<
                 "\" does not match verification value.";
    std::cerr << " Field: " << field_name_;
    std::cerr << ", DBC: " << util::round( dbc_value_, 6 );
    std::cerr << ", Verify: " << util::round( orig_value_, 6 );
    std::cerr << std::endl;
  }

  do_hotfix( this, s );
}

void effect_hotfix_entry_t::apply_hotfix( bool ptr )
{
  const spelleffect_data_t* source_effect = spelleffect_data_t::find( id_, ptr );

  // Cloning the spell chain will guarantee that the effect is also always cloned
  const spell_data_t* s = hotfix_db_.clone_spell( source_effect -> spell() -> id(), ptr );

  spelleffect_data_t* e = hotfix_db_.get_mutable_effect( id_, ptr );
  assert( e );

  dbc_value_ = e -> get_field( field_name_ );
  if ( orig_value_ != -std::numeric_limits<double>::max() &&
       util::round( orig_value_, 6 ) != util::round( dbc_value_, 6 ) )
  {
    std::cerr << "[" << tag_ << "]: Hotfix \"" << note_ << "\" for spell \"" << s -> name_cstr() <<
                 "\" effect #" << ( e -> index() + 1 ) << " does not match verification value.";
    std::cerr << " Field: " << field_name_;
    std::cerr << ", DBC: " << util::round( dbc_value_, 6 );
    std::cerr << ", Verify: " << util::round( orig_value_, 6 );
    std::cerr << std::endl;
  }

  do_hotfix( this, e );
}

spell_data_t* custom_dbc_data_t::get_mutable_spell( unsigned spell_id, bool ptr )
{
  for ( size_t i = 0, end = spells_[ ptr ].size(); i < end; ++i )
  {
    if ( spells_[ ptr ][ i ] -> id() == spell_id )
    {
      return spells_[ ptr ][ i ];
    }
  }

  return 0;
}

const spell_data_t* custom_dbc_data_t::find_spell( unsigned spell_id, bool ptr ) const
{
  for ( size_t i = 0, end = spells_[ ptr ].size(); i < end; ++i )
  {
    if ( spells_[ ptr ][ i ] -> id() == spell_id )
    {
      return spells_[ ptr ][ i ];
    }
  }

  return 0;
}

bool custom_dbc_data_t::add_spell( spell_data_t* spell, bool ptr )
{
  if ( find_spell( spell -> id(), ptr ) )
  {
    return false;
  }

  spells_[ ptr ].push_back( spell );

  return true;
}

spelleffect_data_t* custom_dbc_data_t::get_mutable_effect( unsigned effect_id, bool ptr )
{
  for ( size_t i = 0, end = effects_[ ptr ].size(); i < end; ++i )
  {
    if ( effects_[ ptr ][ i ] -> id() == effect_id )
    {
      return effects_[ ptr ][ i ];
    }
  }

  return 0;
}

const spelleffect_data_t* custom_dbc_data_t::find_effect( unsigned effect_id, bool ptr ) const
{
  for ( size_t i = 0, end = effects_[ ptr ].size(); i < end; ++i )
  {
    if ( effects_[ ptr ][ i ] -> id() == effect_id )
    {
      return effects_[ ptr ][ i ];
    }
  }

  return 0;
}

bool custom_dbc_data_t::add_effect( spelleffect_data_t* effect, bool ptr )
{
  if ( find_effect( effect -> id(), ptr ) )
  {
    return false;
  }

  effects_[ ptr ].push_back( effect );

  return true;
}

spell_data_t* custom_dbc_data_t::create_clone( const spell_data_t* s, bool ptr )
{
  spell_data_t* news = get_mutable_spell( s -> id(), ptr );
  if ( ! news )
  {
    news = new spell_data_t( *s );
    // TODO: Power, not overridable atm so we can use the static data, and the static data vector
    // too.
    news -> _effects = new std::vector<const spelleffect_data_t*>( s -> effect_count(), spelleffect_data_t::nil() );

    add_spell( news, ptr );
  }

  for ( size_t i = 0; i < s -> _effects -> size(); ++i )
  {
    if ( s -> _effects -> at( i ) -> id() == 0 )
    {
      continue;
    }

    spelleffect_data_t* ed = get_mutable_effect( s -> _effects -> at( i ) -> id(), ptr );
    if ( ! ed )
    {
      ed = new spelleffect_data_t( *spelleffect_data_t::find( s -> _effects -> at( i ) -> id(), ptr ) );
      news -> _effects -> at( i ) = ed;
      add_effect( ed, ptr );
    }

    assert( ed -> _spell -> id() == news -> id() );
    ed -> _spell = news;
    if ( s -> _effects -> at( i ) -> trigger() -> id() != 0 )
    {
      // Clone the trigger
      ed -> _trigger_spell = create_clone( s -> _effects -> at( i ) -> trigger(), ptr );
      assert( ed -> _trigger_spell -> _driver &&
              ed -> _trigger_spell -> _driver -> id() == s -> id() );
      // Set the trigger's driver to this spell
      ed -> _trigger_spell -> _driver = news;
    }
  }

  return news;
}

spell_data_t* custom_dbc_data_t::clone_spell( unsigned base_spell_id, bool ptr )
{
  spell_data_t* base_spell = get_mutable_spell( base_spell_id, ptr );
  // If a spell is found, we can be sure that the whole spell chain has already been cloned, so just
  // return the base spell
  if ( base_spell )
  {
    return base_spell;
  }
  else
  {
    base_spell = spell_data_t::find( base_spell_id, ptr );
  }

  // Get to the root of the potential chain
  while ( base_spell -> driver() -> id() != 0 )
  {
    base_spell = base_spell -> driver();
  }

  // Create clone of the whole chain, we don't really care about individual spells for now
  create_clone( base_spell, ptr );

  // Return the cloned spell
  return get_mutable_spell( base_spell_id, ptr );
}

custom_dbc_data_t::~custom_dbc_data_t()
{
  for ( size_t i = 0; i < spells_[ 0 ].size(); ++i )
  {
    delete spells_[ 0 ][ i ] -> _effects;
  }

  for ( size_t i = 0; i < spells_[ 1 ].size(); ++i )
  {
    delete spells_[ 1 ][ i ] -> _effects;
  }
}

namespace dbc_override
{
  custom_dbc_data_t override_db_;
}

bool dbc_override::register_spell( sim_t* sim, unsigned spell_id, const std::string& field, double v )
{
  spell_data_t* spell = override_db_.get_mutable_spell( spell_id, sim -> dbc.ptr );
  if ( ! spell )
  {
    spell = override_db_.clone_spell( spell_id, sim -> dbc.ptr );
  }

  assert( spell );
  spell -> override_field( field, v );

  return true;
}

bool dbc_override::register_effect( sim_t* sim, unsigned effect_id, const std::string& field, double v )
{
  spelleffect_data_t* effect = override_db_.get_mutable_effect( effect_id, sim -> dbc.ptr );
  if ( ! effect )
  {
    const spelleffect_data_t* dbc_effect = sim -> dbc.effect( effect_id );
    override_db_.clone_spell( dbc_effect -> spell() -> id(), sim -> dbc.ptr );
    effect = override_db_.get_mutable_effect( effect_id, sim -> dbc.ptr );
  }

  assert( effect );

  effect -> override_field( field, v );

  return true;
}

const spell_data_t* dbc_override::find_spell( unsigned spell_id, bool ptr )
{
  return override_db_.find_spell( spell_id, ptr );
}
